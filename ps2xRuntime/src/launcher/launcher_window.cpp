#include "launcher_window.h"

#include "dbz_theme.h"
#include "install_wizard_dialog.h"
#include "iso9660.h"
#include "settings_dialog.h"
#include "settings_manager.h"

#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QGuiApplication>
#include <QHBoxLayout>
#include <QLabel>
#include <QPainter>
#include <QProcess>
#include <QPushButton>
#include <QScreen>
#include <QShowEvent>
#include <QStandardPaths>
#include <QTimer>
#include <QVBoxLayout>

#include <cstdio>

namespace
{
    // BT3SELFX footer: the last 32 bytes are "BT3SELFX" magic + payload info.
    bool isSelfExtractElf(const QString &path)
    {
        QFile f(path);
        if (!f.open(QIODevice::ReadOnly))
            return false;
        if (f.size() < 32)
            return false;
        if (!f.seek(f.size() - 32))
            return false;
        QByteArray tail = f.read(8);
        return tail == QByteArray("BT3SELFX");
    }
} // namespace

LauncherWindow::LauncherWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QStringLiteral("Dragon Ball Budokai Tenkaichi 3 Launcher"));
    resize(900, 500);
    setMinimumSize(700, 420);

    // The launcher lives in the deploy root; savedata/ is the shared settings dir.
    m_savedataDir = QDir(QApplication::applicationDirPath()).filePath(QStringLiteral("savedata"));
    m_dataDir = QDir(QApplication::applicationDirPath()).filePath(QStringLiteral("data"));

    // Resolve the game ELF next to the launcher binary.
    const QDir appDir(QApplication::applicationDirPath());
    static const char *kCandidates[] = {
        "Dragon Ball - Budokai Tenkaichi 3",
        "Dragon Ball Budokai Tenkaichi 3",
        "SLUS-216.78",
    };
    for (const char *c : kCandidates)
    {
        const QString p = appDir.filePath(QString::fromLatin1(c));
        if (QFile::exists(p) && isSelfExtractElf(p))
        {
            m_gameElf = p;
            break;
        }
    }

    // Background: deploy assets/background.png if present, else a DBZ gradient.
    const QString bg = appDir.filePath(QStringLiteral("assets/background.png"));
    if (QFile::exists(bg))
        m_bgPath = bg;

    // Bottom bar with PLAY (left) + SETTINGS (right).
    auto *bottomBar = new QWidget(this);
    bottomBar->setObjectName(QStringLiteral("bottomBar"));
    // Opaque bar: solid background over the image area, only a top edge line.
    bottomBar->setStyleSheet(QStringLiteral(
        "QWidget#bottomBar { background-color: #0b0f13; border-top: 1px solid #1e2830; }"));
    m_bottomBar = bottomBar;

    auto *barLayout = new QHBoxLayout(bottomBar);
    barLayout->setContentsMargins(24, 14, 24, 14);

    m_play = new QPushButton(QStringLiteral("PLAY"), bottomBar);
    m_play->setObjectName(QStringLiteral("playButton"));
    m_play->setCursor(Qt::PointingHandCursor);
    m_play->setFixedHeight(58);

    m_settings = new QPushButton(QStringLiteral("SETTINGS"), bottomBar);
    m_settings->setObjectName(QStringLiteral("settingsButton"));
    m_settings->setCursor(Qt::PointingHandCursor);
    m_settings->setFixedHeight(50);

    barLayout->addWidget(m_play, 0, Qt::AlignVCenter);
    barLayout->addStretch(1);
    barLayout->addWidget(m_settings, 0, Qt::AlignVCenter);

    m_hint = new QLabel(bottomBar);
    m_hint->setObjectName(QStringLiteral("hintLabel"));
    m_hint->setStyleSheet(QStringLiteral("color: #9999b3; background: transparent;"));

    auto *root = new QWidget(this);
    root->setObjectName(QStringLiteral("launcherRoot"));
    // Keep the central container transparent so the background image painted
    // in paintEvent() actually shows through (the global QSS otherwise paints
    // an opaque WindowBg over it).
    root->setAttribute(Qt::WA_TranslucentBackground, true);
    root->setStyleSheet(QStringLiteral("QWidget#launcherRoot { background: transparent; }"));
    auto *layout = new QVBoxLayout(root);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    layout->addStretch(1);
    layout->addWidget(bottomBar);
    setCentralWidget(root);

    connect(m_play, &QPushButton::clicked, this, &LauncherWindow::onPlayClicked);
    connect(m_settings, &QPushButton::clicked, this, &LauncherWindow::onSettingsClicked);

    // Show detected game / missing state in the bar.
    if (m_gameElf.isEmpty())
        m_hint->setText(QStringLiteral("  no self-extracting game ELF found in this folder"));
    else
        m_hint->setText(QStringLiteral("  %1").arg(QFileInfo(m_gameElf).fileName()));
    barLayout->insertWidget(1, m_hint, 1, Qt::AlignVCenter | Qt::AlignLeft);

    checkGameData();

    // Seed settings manager from the shared savedata dir.
    SettingsManager::instance().setConfigDir(m_savedataDir);
    SettingsManager::instance().load();
}

QString LauncherWindow::findGameElf()
{
    const QDir appDir(QApplication::applicationDirPath());
    static const char *kCandidates[] = {
        "Dragon Ball - Budokai Tenkaichi 3",
        "Dragon Ball Budokai Tenkaichi 3",
        "SLUS-216.78",
    };
    for (const char *c : kCandidates)
    {
        const QString p = appDir.filePath(QString::fromLatin1(c));
        if (QFile::exists(p) && isSelfExtractElf(p))
            return p;
    }
    return QString();
}

void LauncherWindow::onPlayClicked()
{
    if (m_gameElf.isEmpty())
    {
        m_gameElf = findGameElf();
        if (m_gameElf.isEmpty())
            return;
    }

    // Game data must be present and validated before the runner can boot.
    if (!m_gameDataValid)
    {
        // The install wizard restores data on success.
        if (!openInstallWizard())
            return;
    }

    // Save any pending settings so the game boots with the launcher's config.
    SettingsManager::instance().save();

    // Launch detached: the game extracts + execs its own inner runner.
    QProcess *proc = new QProcess(nullptr);
    proc->setWorkingDirectory(QFileInfo(m_gameElf).absolutePath());
    proc->setProgram(m_gameElf);
    proc->startDetached();

    // The launcher's job is done: close this window (the game runs on its own).
    close();
}

void LauncherWindow::checkGameData()
{
    m_gameDataValid = (DiscVerify::verifyInstalledData(m_dataDir) == DiscVerify::State::Valid);

    if (m_play)
        m_play->setEnabled(!m_gameElf.isEmpty() && m_gameDataValid);

    if (!m_gameElf.isEmpty() && !m_gameDataValid)
    {
        m_hint->setText(QStringLiteral("  game data missing or corrupted - reinstall required"));
    }
}

bool LauncherWindow::openInstallWizard()
{
    InstallWizardDialog dlg(this);
    const bool installed = dlg.exec() == QDialog::Accepted;
    checkGameData();
    return installed && m_gameDataValid;
}

void LauncherWindow::showEvent(QShowEvent *e)
{
    QMainWindow::showEvent(e);

    // Pop the install wizard automatically on first launch when the game data
    // is missing/corrupt. The subsequent runs are user-initiated (PLAY button).
    if (!m_gameDataValid && !m_wizardShown)
    {
        m_wizardShown = true;
        QTimer::singleShot(0, this, [this] {
            if (!m_gameDataValid)
                openInstallWizard();
        });
    }
}

void LauncherWindow::onSettingsClicked()
{
    SettingsDialog dlg(this);
    dlg.exec();
}

void LauncherWindow::loadBackground() { /* bg applied in paintEvent */ }

void LauncherWindow::paintEvent(QPaintEvent *)
{
    // The background image only fills the area above the (opaque) bottom bar.
    const int barY = m_bottomBar ? m_bottomBar->y() : height();
    const QRect bgArea(0, 0, width(), barY);

    QPainter p(this);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    if (!m_bgPath.isEmpty())
    {
        QPixmap bg(m_bgPath);
        if (!bg.isNull())
        {
            p.drawPixmap(bgArea, bg.scaled(bgArea.size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation));
            return;
        }
    }
    // Fallback: dark DBZ gradient (top->bottom) within the image area.
    QLinearGradient g(0, 0, 0, bgArea.height());
    g.setColorAt(0.0, QColor(16, 22, 28));
    g.setColorAt(0.5, QColor(9, 14, 18));
    g.setColorAt(1.0, QColor(5, 8, 12));
    p.fillRect(bgArea, g);

    // Corner brackets (accent orange), matching the capsule-HUD look.
    const QColor bracket(255, 158, 26, 200);
    QPen pen(bracket, 2.0);
    p.setPen(pen);
    const int bl = 14, off = 6;
    const QRect r = bgArea.adjusted(1, 1, -1, -1);
    QPoint tl = r.topLeft(), tr = r.topRight(), blc = r.bottomLeft(), br = r.bottomRight();
    p.drawLine(tl + QPoint(off, off), tl + QPoint(off + bl, off));
    p.drawLine(tl + QPoint(off, off), tl + QPoint(off, off + bl));
    p.drawLine(tr - QPoint(off, off), tr - QPoint(off + bl, -off));
    p.drawLine(tr - QPoint(off, off), tr - QPoint(-off, off + bl));
    p.drawLine(blc + QPoint(off, -off), blc + QPoint(off + bl, -off));
    p.drawLine(blc + QPoint(off, -off), blc + QPoint(off, -off - bl));
    p.drawLine(br - QPoint(off, -off), br - QPoint(off + bl, -off));
    p.drawLine(br - QPoint(off, -off), br - QPoint(-off, off + bl));
}