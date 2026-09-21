#include "app_paths.h"
#include "install_wizard_dialog.h"

#include "afs_extract_worker.h"
#include "archive_extract.h"
#include "extract_worker.h"
#include "iso9660.h"
#include "recommendation.h"

#include <QApplication>
#include <QColor>
#include <QCoreApplication>
#include <QDir>
#include <QDirIterator>
#include <QEasingCurve>
#include <QFile>
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QProgressBar>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QStackedWidget>
#include <QTemporaryDir>
#include <QThread>
#include <QVBoxLayout>

#include <utility>

namespace
{
constexpr qint64 kMiB = 1024 * 1024;

QString fmtMb(qint64 bytes)
{
    return QString::number(bytes / kMiB);
}

// [verbose] ETA from the bytes-per-ms rate observed so far.
QString fmtEta(qint64 done, qint64 total, qint64 elapsedMs)
{
    if (done <= 0 || total <= done || elapsedMs <= 0)
        return QString();
    const double rate = static_cast<double>(done) / static_cast<double>(elapsedMs);
    if (rate <= 0.0)
        return QString();
    qint64 remainMs = static_cast<qint64>(static_cast<double>(total - done) / rate);
    if (remainMs < 0)
        remainMs = 0;
    const qint64 sec = remainMs / 1000;
    return QStringLiteral("~%1:%2 remaining").arg(sec / 60).arg(sec % 60, 2, 10, QLatin1Char('0'));
}

QString findImageRecursive(const QString &root, int depth)
{
    if (depth > 3)
        return QString();
    QDirIterator it(root, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        const QString n = it.fileName().toLower();
        if (n.endsWith(QLatin1String(".iso")) || n.endsWith(QLatin1String(".img"))
            || n.endsWith(QLatin1String(".bin")))
            return it.filePath();
    }
    return QString();
}

// Any PZS3US*.AFS left next to the extracted game data (their parent folder is
// the deploy dir the runtime reads from).
QStringList findAfsContainers(const QString &dataDir)
{
    QStringList out;
    QDirIterator it(dataDir, QDir::Files, QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        it.next();
        const QString n = it.fileName().toUpper();
        if (n.startsWith(QLatin1String("PZS3US")) && n.endsWith(QLatin1String(".AFS")))
            out << it.filePath();
    }
    out.sort();
    return out;
}

} // namespace

InstallWizardView::InstallWizardView(QWidget *parent, bool reinstall)
    : QWidget(parent)
{
    // [inwindow] Fills the launcher window (opaque) instead of a popup dialog.
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(QStringLiteral("InstallWizardView { background-color: #0a1014; }"));
    setMinimumSize(520, 330);
    m_hw = hw::detect();   // [tier] probe once, reused for the Page D summary
    buildUi();
    m_reinstall = reinstall;
    if (reinstall)
        setIndex(1); // straight to the disc dump selection
}

InstallWizardView::~InstallWizardView()
{
    if (m_benchThread)
    {
        m_benchThread->wait(1000);
        m_benchThread->deleteLater();
    }
    delete m_tmp;
}

void InstallWizardView::finish(bool accepted)
{
    if (onFinished)
        onFinished(accepted);
}

void InstallWizardView::buildUi()
{
    auto *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    m_stack = new QStackedWidget(this);
    mainLayout->addWidget(m_stack);

    // --- Page A: welcome / (re)install --------------------------------------
    auto *pageA = new QWidget;
    {
        auto *l = new QVBoxLayout(pageA);
        l->setContentsMargins(28, 24, 28, 24);
        auto *kicker = new QLabel(QStringLiteral("INSTALLATION WIZARD"), pageA);
        kicker->setStyleSheet(QStringLiteral("font-size: 12px; font-weight: 600; color: #8b93a3; letter-spacing: 1px;"));
        l->addWidget(kicker);
        l->addSpacing(4);
        auto *head = new QLabel(QStringLiteral("Welcome to Budokai Tenkaichi 3 Recompiled"), pageA);
        head->setWordWrap(true);
        head->setStyleSheet(QStringLiteral("font-size: 18px; font-weight: 600; color: #ffd9a0;"));
        l->addWidget(head);
        l->addSpacing(10);
        auto *body = new QLabel(QStringLiteral(
            "Before you play, we'll install the game files from <b>your own disc dump</b>.<br><br>"
            "<b>Next steps:</b><br>"
            "&nbsp;&nbsp;1.&nbsp; Point the wizard at your BT3 disc dump (ISO or archive).<br>"
            "&nbsp;&nbsp;2.&nbsp; We verify it and extract the game data into this folder.<br><br>"
            "This runs <b>once</b>; your saves and settings are kept."), pageA);
        body->setWordWrap(true);
        body->setTextFormat(Qt::RichText);
        body->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(body);
        l->addStretch(1);

        auto *row = new QHBoxLayout;
        row->addStretch(1);
        m_nextMissing = new QPushButton(QStringLiteral("Next"), pageA);
        m_nextMissing->setObjectName(QStringLiteral("wizardButton"));
        m_nextMissing->setCursor(Qt::PointingHandCursor);
        connect(m_nextMissing, &QPushButton::clicked, this, &InstallWizardView::onNextMissing);
        row->addWidget(m_nextMissing);
        l->addLayout(row);
    }
    m_stack->addWidget(pageA);

    // --- Page B: locate + validate the disc dump -----------------------------
    auto *pageB = new QWidget;
    {
        auto *l = new QVBoxLayout(pageB);
        l->setContentsMargins(28, 24, 28, 24);
        auto *head = new QLabel(QStringLiteral("Install game data"), pageB);
        head->setStyleSheet(QStringLiteral("font-size: 17px; font-weight: 600; color: #ffd9a0;"));
        l->addWidget(head);
        l->addSpacing(8);

        auto *prompt = new QLabel(
            QStringLiteral("Please introduce the directory to your own game disc dump to install:"), pageB);
        prompt->setWordWrap(true);
        prompt->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(prompt);
        l->addSpacing(10);

        auto *row = new QHBoxLayout;
        m_selected = new QLabel(QStringLiteral("No file selected"), pageB);
        m_selected->setWordWrap(true);
        m_selected->setStyleSheet(QStringLiteral("font-size: 12px; color: #8b93a3;"));
        row->addWidget(m_selected, 1);
        m_browse = new QPushButton(QStringLiteral("Browse…"), pageB);
        m_browse->setObjectName(QStringLiteral("wizardButton"));
        m_browse->setCursor(Qt::PointingHandCursor);
        connect(m_browse, &QPushButton::clicked, this, &InstallWizardView::onBrowse);
        row->addWidget(m_browse);
        l->addLayout(row);
        l->addSpacing(12);

        auto *dots = new QHBoxLayout;
        m_dot = new QLabel(QStringLiteral("●"), pageB);
        m_dot->setStyleSheet(QStringLiteral("font-size: 15px; color: #8b93a3;"));
        dots->addWidget(m_dot);
        m_dotText = new QLabel(QStringLiteral("Awaiting a disc dump…"), pageB);
        m_dotText->setWordWrap(true);
        m_dotText->setStyleSheet(QStringLiteral("font-size: 13px; color: #8b93a3;"));
        dots->addWidget(m_dotText, 1);
        l->addLayout(dots);
        l->addStretch(1);

        auto *rowB = new QHBoxLayout;
        auto *backB = new QPushButton(QStringLiteral("Back"), pageB);
        backB->setObjectName(QStringLiteral("wizardButton"));
        backB->setCursor(Qt::PointingHandCursor);
        connect(backB, &QPushButton::clicked, this, [this] { setIndex(0); });
        rowB->addWidget(backB);
        rowB->addStretch(1);
        m_retryDump = new QPushButton(QStringLiteral("Retry"), pageB);
        m_retryDump->setObjectName(QStringLiteral("wizardButton"));
        m_retryDump->setCursor(Qt::PointingHandCursor);
        m_retryDump->setVisible(false);
        connect(m_retryDump, &QPushButton::clicked, this, &InstallWizardView::onRetryDump);
        rowB->addWidget(m_retryDump);
        rowB->addSpacing(8);
        m_nextDump = new QPushButton(QStringLiteral("Next"), pageB);
        m_nextDump->setObjectName(QStringLiteral("wizardButton"));
        m_nextDump->setCursor(Qt::PointingHandCursor);
        m_nextDump->setEnabled(false);
        connect(m_nextDump, &QPushButton::clicked, this, &InstallWizardView::onInstall);
        rowB->addWidget(m_nextDump);
        l->addLayout(rowB);
    }
    m_stack->addWidget(pageB);

    // --- Page C: installation progress ---------------------------------------
    auto *pageC = new QWidget;
    {
        auto *l = new QVBoxLayout(pageC);
        l->setContentsMargins(28, 24, 28, 24);
        auto *head = new QLabel(QStringLiteral("Installation in progress"), pageC);
        head->setStyleSheet(QStringLiteral("font-size: 17px; font-weight: 600; color: #ffd9a0;"));
        l->addWidget(head);
        l->addSpacing(12);

        m_progressText = new QLabel(QStringLiteral("0 MB / 0 MB"), pageC);
        m_progressText->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(m_progressText);

        m_bar = new QProgressBar(pageC);
        m_bar->setRange(0, 1);
        m_bar->setValue(0);
        m_bar->setTextVisible(false);
        m_bar->setStyleSheet(QStringLiteral(
            "QProgressBar { background:#1b222b; border:1px solid #2a3542; border-radius:4px; height:14px; }"
            "QProgressBar::chunk { background:#ff9e1a; border-radius:4px; }"));
        l->addWidget(m_bar);
        l->addSpacing(6);

        m_activity = new QLabel(QString(), pageC);
        m_activity->setWordWrap(true);
        m_activity->setStyleSheet(QStringLiteral("font-size: 12px; color: #8b93a3;"));
        l->addWidget(m_activity);
        l->addSpacing(6);

        m_doneLabel = new QLabel(QString(), pageC);
        m_doneLabel->setWordWrap(true);
        m_doneLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(m_doneLabel);
        l->addStretch(1);

        auto *rowC = new QHBoxLayout;
        rowC->addStretch(1);
        m_retryInstall = new QPushButton(QStringLiteral("Retry"), pageC);
        m_retryInstall->setObjectName(QStringLiteral("wizardButton"));
        m_retryInstall->setCursor(Qt::PointingHandCursor);
        m_retryInstall->setVisible(false);
        connect(m_retryInstall, &QPushButton::clicked, this, &InstallWizardView::onRetryInstall);
        rowC->addWidget(m_retryInstall);
        rowC->addSpacing(8);
        m_close = new QPushButton(QStringLiteral("Close"), pageC);
        m_close->setObjectName(QStringLiteral("wizardButton"));
        m_close->setCursor(Qt::PointingHandCursor);
        connect(m_close, &QPushButton::clicked, this, [this] {
            if (m_installed)
                finish(true);
            else
                finish(false);
        });
        rowC->addWidget(m_close);
        l->addLayout(rowC);
    }
    m_stack->addWidget(pageC);

    // --- Page D: post-install summary + hardware + recommendation -----------
    auto *pageD = new QWidget;
    {
        auto *l = new QVBoxLayout(pageD);
        l->setContentsMargins(28, 24, 28, 24);
        auto *kicker = new QLabel(QStringLiteral("INSTALLATION COMPLETE"), pageD);
        kicker->setStyleSheet(QStringLiteral("font-size: 12px; font-weight: 600; color: #8b93a3; letter-spacing: 1px;"));
        l->addWidget(kicker);
        l->addSpacing(4);
        auto *head = new QLabel(QStringLiteral("Summary"), pageD);
        head->setStyleSheet(QStringLiteral("font-size: 18px; font-weight: 600; color: #ffd9a0;"));
        l->addWidget(head);
        l->addSpacing(10);

        m_summary = new QLabel(pageD);
        m_summary->setWordWrap(true);
        m_summary->setTextFormat(Qt::RichText);
        m_summary->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(m_summary);
        l->addSpacing(12);

        m_hwLabel = new QLabel(pageD);
        m_hwLabel->setWordWrap(true);
        m_hwLabel->setTextFormat(Qt::RichText);
        m_hwLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        l->addWidget(m_hwLabel);
        l->addSpacing(6);

        m_recLabel = new QLabel(pageD);
        m_recLabel->setWordWrap(true);
        m_recLabel->setTextFormat(Qt::RichText);
        m_recLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #ffd9a0;"));
        l->addWidget(m_recLabel);
        l->addSpacing(8);

        m_applyBtn = new QPushButton(QStringLiteral("Apply recommended settings"), pageD);
        m_applyBtn->setObjectName(QStringLiteral("wizardButton"));
        m_applyBtn->setCursor(Qt::PointingHandCursor);
        connect(m_applyBtn, &QPushButton::clicked, this, [this] {
            rec::apply(m_rec);
            m_applyBtn->setText(QStringLiteral("Applied \u2713"));
            m_applyBtn->setEnabled(false);
        });
        l->addWidget(m_applyBtn);
        l->addSpacing(12);

        auto *tip = new QLabel(QStringLiteral(
            "Tip: you can download a <b>4K texture pack</b> any time from "
            "<b>Settings &rarr; Video &rarr; Texture Replacement…</b>"), pageD);
        tip->setWordWrap(true);
        tip->setTextFormat(Qt::RichText);
        tip->setStyleSheet(QStringLiteral("font-size: 12px; color: #8b93a3;"));
        l->addWidget(tip);
        l->addStretch(1);

        auto *rowD = new QHBoxLayout;
        m_openSettingsBtn = new QPushButton(QStringLiteral("Open Settings"), pageD);
        m_openSettingsBtn->setObjectName(QStringLiteral("wizardButton"));
        m_openSettingsBtn->setCursor(Qt::PointingHandCursor);
        connect(m_openSettingsBtn, &QPushButton::clicked, this, [this] {
            m_openSettings = true;
            finish(true);
        });
        auto *closeD = new QPushButton(QStringLiteral("Close"), pageD);
        closeD->setObjectName(QStringLiteral("wizardButton"));
        closeD->setCursor(Qt::PointingHandCursor);
        connect(closeD, &QPushButton::clicked, this, [this] { finish(true); });
        m_playBtn = new QPushButton(QStringLiteral("Play"), pageD);
        m_playBtn->setObjectName(QStringLiteral("saveButton"));   // accent
        m_playBtn->setCursor(Qt::PointingHandCursor);
        connect(m_playBtn, &QPushButton::clicked, this, [this] {
            m_playRequested = true;
            finish(true);
        });
        rowD->addWidget(m_openSettingsBtn);
        rowD->addStretch(1);
        rowD->addWidget(closeD);
        rowD->addSpacing(8);
        rowD->addWidget(m_playBtn);
        l->addLayout(rowD);

        // [glow] Pulse the "Open Settings" button.
        auto *fx = new QGraphicsDropShadowEffect(m_openSettingsBtn);
        fx->setColor(QColor(255, 158, 26, 200));
        fx->setBlurRadius(18);
        fx->setOffset(0, 0);
        m_openSettingsBtn->setGraphicsEffect(fx);
        auto *anim = new QPropertyAnimation(fx, "blurRadius", m_openSettingsBtn);
        anim->setDuration(1100);
        anim->setStartValue(8.0);
        anim->setEndValue(28.0);
        anim->setEasingCurve(QEasingCurve::InOutSine);
        anim->setLoopCount(-1);
        anim->start();
    }
    m_stack->addWidget(pageD);
}

void InstallWizardView::setIndex(int index)
{
    if (index == 1)
        m_retryDump->setVisible(false);
    if (index == 1 && !m_benchThread)
    {
        // [tier] Silent single-thread CPU benchmark while the user picks/verifies the
        // dump; the result feeds the Page D recommendation.
        m_benchThread = QThread::create([this] { m_cpuR.store(hw::benchSingleThreadR()); });
        m_benchThread->start();
    }
    m_stack->setCurrentIndex(index);
}

void InstallWizardView::onNextMissing()
{
    setIndex(1);
}

void InstallWizardView::onBrowse()
{
    static const QString kFilter =
        QStringLiteral("Game disc dump (*.iso *.img *.rar *.7z *.zip *.tar *.tar.gz);;All files (*)");
    // Qt's own dialog (not the native GTK/portal one) so the app's DBZ theme
    // applies: lighter slate background + white text, readable over dark desks.
    const QString path = QFileDialog::getOpenFileName(
        this, QStringLiteral("Select your own game disc dump"), QDir::homePath(), kFilter,
        nullptr, QFileDialog::DontUseNativeDialog);
    if (path.isEmpty())
        return;
    m_selected->setText(QDir::toNativeSeparators(path));
    attemptVerify(path);
}

void InstallWizardView::onRetryDump()
{
    attemptVerify(m_dumpPath);
}

void InstallWizardView::setVerified(bool ok, const QString &text)
{
    m_verified = ok;
    m_dot->setStyleSheet(QStringLiteral("font-size: 15px; color: %1;")
                             .arg(ok ? QStringLiteral("#22c55e") : QStringLiteral("#ef4444")));
    m_dotText->setStyleSheet(QStringLiteral("font-size: 13px; color: %1;")
                                 .arg(ok ? QStringLiteral("#22c55e") : QStringLiteral("#ef4444")));
    m_dotText->setText(text);
    m_nextDump->setEnabled(ok);
}

void InstallWizardView::attemptVerify(const QString &dumpPath)
{
    m_dumpPath = dumpPath;
    m_retryDump->setVisible(false);
    auto status = [this](const QString &t) {
        m_dot->setStyleSheet(QStringLiteral("font-size: 15px; color: #8b93a3;"));
        m_dotText->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
        m_dotText->setText(t);
        QCoreApplication::processEvents();
    };

    const QString lower = dumpPath.toLower();
    const bool isImage = lower.endsWith(QLatin1String(".iso")) || lower.endsWith(QLatin1String(".img"));

    if (!isImage)
    {
        if (!m_tmp)
            m_tmp = new QTemporaryDir;
        QString err;
        status(QStringLiteral("Opening archive…"));
        status(QStringLiteral("Extracting archive…"));
        m_isoPath = resolveInnerImage(dumpPath, &err);
        if (m_isoPath.isEmpty())
        {
            setVerified(false, err);
            m_retryDump->setVisible(true);
            return;
        }
        status(QStringLiteral("Disc image found: %1").arg(QDir::toNativeSeparators(m_isoPath)));
    }
    else
    {
        m_isoPath = dumpPath;
        status(QStringLiteral("Disc image selected."));
    }

    status(QStringLiteral("Verifying game disc (SLUS_216.78)…"));
    if (DiscVerify::verifySlusFromIso(m_isoPath))
        setVerified(true, QStringLiteral("Game Disc Validated"));
    else
        setVerified(false, QStringLiteral("Cannot verify game disc. Is it the right version?"));
}

QString InstallWizardView::resolveInnerImage(const QString &dumpPath, QString *err)
{
    const QString unpackDir = m_tmp->path() + QStringLiteral("/unpack");
    if (!QDir().mkpath(unpackDir))
    {
        *err = QStringLiteral("The extraction failed. Please extract the ISO manually.");
        return QString();
    }

    // libarchive, in-process: same code path on every platform, no external 7z.
    QString extractErr;
    const bool ok = archivex::extract(
        dumpPath, unpackDir,
        [](quint64, quint64) {
            QCoreApplication::processEvents(QEventLoop::AllEvents, 30);
            return true;
        },
        &extractErr);
    if (!ok)
    {
        *err = QStringLiteral("The extraction failed. Please extract the ISO manually.");
        return QString();
    }

    const QString image = findImageRecursive(unpackDir, 3);
    if (image.isEmpty())
        *err = QStringLiteral("The extraction failed. Please extract the ISO manually.");
    return image;
}

void InstallWizardView::onInstall()
{
    if (!m_verified || m_isoPath.isEmpty())
        return;
    startExtraction();
}

void InstallWizardView::onRetryInstall()
{
    if (m_inAfsPhase)
    {
        startAfsConversion();
        return;
    }
    if (m_isoPath.isEmpty())
    {
        setIndex(1);
        return;
    }
    startExtraction();
}

void InstallWizardView::startExtraction()
{
    m_bar->setRange(0, 1);
    m_bar->setValue(0);
    m_progressText->setText(QStringLiteral("0 MB / 0 MB"));
    m_activity->clear();
    m_timer.restart();   // [verbose] ETA base
    m_doneLabel->setText(QStringLiteral("Installation in progress…"));
    m_doneLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
    m_retryInstall->setVisible(false);
    m_close->setEnabled(false);
    setIndex(2);
    QCoreApplication::processEvents();

    m_thread = new QThread;
    m_worker = new ExtractWorker;
    m_worker->moveToThread(m_thread);
    connect(m_thread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_thread, &QThread::finished, m_thread, &QObject::deleteLater);
    connect(m_worker, &ExtractWorker::file, this, [this](const QString &p) {
        m_activity->setText(QStringLiteral("Extracting %1").arg(p));
    });
    connect(m_worker, &ExtractWorker::progress, this, &InstallWizardView::onExtractProgress);
    connect(m_worker, &ExtractWorker::done, this, &InstallWizardView::onExtractDone);
    connect(m_worker, &ExtractWorker::done, m_thread, &QThread::quit);
    m_thread->start();

    const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
    QMetaObject::invokeMethod(m_worker, "doWork", Qt::QueuedConnection, Q_ARG(QString, m_isoPath),
                              Q_ARG(QString, dataDir));
}

void InstallWizardView::onExtractProgress(qint64 done, qint64 total)
{
    if (total > 0)
        m_bar->setRange(0, static_cast<int>(total / (64 * 1024)));
    m_bar->setValue(static_cast<int>(done / (64 * 1024)));
    QString t = QStringLiteral("%1 MB / %2 MB").arg(fmtMb(done)).arg(fmtMb(total));
    const QString eta = fmtEta(done, total, m_timer.elapsed());
    if (!eta.isEmpty())
        t += QStringLiteral("   ·   ") + eta;
    m_progressText->setText(t);
}

void InstallWizardView::onExtractDone(bool ok, const QString &msg)
{
    if (ok)
    {
        const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
        if (!findAfsContainers(dataDir).isEmpty())
        {
            startAfsConversion();
            return;
        }
        applyInstallResult(true, QStringLiteral("Installation complete. Game disc validated."));
        return;
    }
    applyInstallResult(false, msg);
}

void InstallWizardView::startAfsConversion()
{
    const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
    const QStringList afs = findAfsContainers(dataDir);
    if (afs.isEmpty())
    {
        applyInstallResult(true, QStringLiteral("Installation complete. Game disc validated."));
        return;
    }

    m_inAfsPhase = true;
    m_retryInstall->setVisible(false);
    m_close->setEnabled(false);
    m_bar->setRange(0, 1);
    m_bar->setValue(0);
    m_progressText->setText(QStringLiteral("0 MB / 0 MB"));
    m_doneLabel->setText(QStringLiteral("Converting game data to folders…"));
    m_doneLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #c9ccd4;"));
    m_activity->setText(QStringLiteral("Preparing…"));
    m_timer.restart();   // [verbose] ETA base
    QCoreApplication::processEvents();

    m_afsThread = new QThread;
    m_afsWorker = new AfsExtractWorker;
    m_afsWorker->moveToThread(m_afsThread);
    connect(m_afsThread, &QThread::finished, m_afsWorker, &QObject::deleteLater);
    connect(m_afsThread, &QThread::finished, m_afsThread, &QObject::deleteLater);
    connect(m_afsWorker, &AfsExtractWorker::status, this, &InstallWizardView::onAfsStatus);
    connect(m_afsWorker, &AfsExtractWorker::progress, this, &InstallWizardView::onAfsProgress);
    connect(m_afsWorker, &AfsExtractWorker::done, this, &InstallWizardView::onAfsDone);
    connect(m_afsWorker, &AfsExtractWorker::done, m_afsThread, &QThread::quit);
    m_afsThread->start();

    QMetaObject::invokeMethod(m_afsWorker, "doWork", Qt::QueuedConnection, Q_ARG(QStringList, afs));
}

void InstallWizardView::onAfsStatus(const QString &text)
{
    m_activity->setText(text);
}

void InstallWizardView::onAfsProgress(qint64 done, qint64 total)
{
    if (total > 0)
        m_bar->setRange(0, static_cast<int>(total / (64 * 1024)));
    m_bar->setValue(static_cast<int>(done / (64 * 1024)));
    QString t = QStringLiteral("%1 MB / %2 MB").arg(fmtMb(done)).arg(fmtMb(total));
    const QString eta = fmtEta(done, total, m_timer.elapsed());
    if (!eta.isEmpty())
        t += QStringLiteral("   ·   ") + eta;
    m_progressText->setText(t);
}

void InstallWizardView::onAfsDone(bool ok, const QString &msg)
{
    m_inAfsPhase = false;
    m_activity->clear();
    if (ok)
        applyInstallResult(true, QStringLiteral("Installation complete. Game data converted to folders."));
    else
        applyInstallResult(false, msg);
}

void InstallWizardView::applyInstallResult(bool ok, const QString &msg)
{
    if (ok)
    {
        m_installed = true;
        m_doneLabel->setText(msg);
        m_doneLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #22c55e;"));
        m_bar->setValue(m_bar->maximum());
        m_close->setEnabled(true);
        if (!m_reinstall)
        {
            // [summary] Page D: install summary + hardware + recommendation.
            if (m_benchThread && !m_benchThread->isFinished())
                m_benchThread->wait(500);
            const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
            const double gb = DiscVerify::dataSize(dataDir) / (1024.0 * 1024.0 * 1024.0);
            m_summary->setText(QStringLiteral(
                "<b>&#10004; Installed</b><br>"
                "&nbsp;&nbsp;&bull; Game data &mdash; %1 GB &rarr; %2<br>"
                "&nbsp;&nbsp;&bull; Game disc validated (SLUS_216.78)<br>"
                "&nbsp;&nbsp;&bull; AFS containers converted to folders")
                    .arg(QString::number(gb, 'f', 2), QDir::toNativeSeparators(dataDir)));
            m_rec = hw::recommend(m_hw, m_cpuR.load());
            m_hwLabel->setText(QStringLiteral("<b>Your hardware</b><br>&nbsp;&nbsp;%1").arg(hw::summary(m_hw)));
            m_recLabel->setText(QStringLiteral(
                "<b>Recommended settings</b> (%1)<br>"
                "&nbsp;&nbsp;Render scale %2x &nbsp;&middot;&nbsp; Widescreen %3 &nbsp;&middot;&nbsp; "
                "Texture pack %4 &nbsp;&middot;&nbsp; %5 fps")
                    .arg(m_rec.tierName)
                    .arg(m_rec.renderScale)
                    .arg(m_rec.widescreen ? QStringLiteral("ON") : QStringLiteral("OFF"))
                    .arg(m_rec.texPackFull ? QStringLiteral("Full") : QStringLiteral("Off/Lite"))
                    .arg(m_rec.fps60 ? 60 : 30));
            setIndex(3); // summary page (first install only)
        }
        return;
    }
    else
    {
        m_doneLabel->setText(msg.isEmpty() ? QStringLiteral("Installation failed.") : msg);
        m_doneLabel->setStyleSheet(QStringLiteral("font-size: 13px; color: #ef4444;"));
        m_retryInstall->setVisible(true);
    }
    m_close->setEnabled(true);
}