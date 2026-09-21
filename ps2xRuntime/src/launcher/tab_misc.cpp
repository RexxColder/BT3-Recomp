#include "app_paths.h"
#include "tab_misc.h"

#include "install_wizard_dialog.h"
#include "iso9660.h"
#include "settings_manager.h"
#include "view_host.h"

#include <QApplication>
#include <QCheckBox>
#include <QDesktopServices>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QScrollArea>
#include <QSignalBlocker>
#include <QUrl>
#include <QVBoxLayout>

namespace
{
QString fmtSize(quint64 bytes)
{
    const QString gb = QString::number(bytes / (1024.0 * 1024.0 * 1024.0), 'f', 2);
    return QStringLiteral("%1 GB").arg(gb);
}
} // namespace

MiscTab::MiscTab(QWidget *parent)
    : QWidget(parent)
{
    auto *scroll = new QScrollArea(this);
    scroll->setWidgetResizable(true);
    scroll->setFrameShape(QFrame::NoFrame);

    auto *content = new QWidget;
    auto *root = new QVBoxLayout(content);
    root->setContentsMargins(14, 12, 14, 12);
    root->setSpacing(6);

    auto section = [](const QString &text) {
        auto *l = new QLabel(text);
        l->setObjectName(QStringLiteral("sectionLabel"));
        return l;
    };

    root->addWidget(section(QStringLiteral("GAME DATA")));

    // Size row.
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Size"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        lbl->setMinimumWidth(110);
        m_size = new QLabel;
        m_size->setObjectName(QStringLiteral("valueLabel"));
        m_size->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        lay->addWidget(lbl);
        lay->addStretch(1);
        lay->addWidget(m_size);
        root->addWidget(row);
    }

    // Validity row (colored dot + label).
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Status"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        lbl->setMinimumWidth(110);
        m_dot = new QLabel(QStringLiteral("●"));
        m_dot->setStyleSheet(QStringLiteral("font-size: 15px; color: #8b93a3;"));
        m_dotText = new QLabel;
        m_dotText->setObjectName(QStringLiteral("hintLabel"));
        m_dotText->setWordWrap(true);
        lay->addWidget(lbl);
        lay->addWidget(m_dot);
        lay->addWidget(m_dotText, 1);
        root->addWidget(row);
    }

    // Folder row: opens the installed game-data folder.
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Folder"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        lbl->setMinimumWidth(110);
        m_browse = new QPushButton(QStringLiteral("Browse…"), row);
        m_browse->setObjectName(QStringLiteral("wizardButton"));
        m_browse->setCursor(Qt::PointingHandCursor);
        lay->addWidget(lbl);
        lay->addStretch(1);
        lay->addWidget(m_browse);
        root->addWidget(row);
    }

    root->addSpacing(4);

    // Reinstall mode toggle -> reveals the Install Wizard button (GAME DATA section).
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Reinstall Mode"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        m_reinstall = new QCheckBox;
        m_reinstall->setObjectName(QStringLiteral("reinstallModeCheck"));
        lay->addWidget(lbl, 1);
        lay->addWidget(m_reinstall);
        root->addWidget(row);
    }

    m_wizardBtn = new QPushButton(QStringLiteral("Installation wizard…"), content);
    m_wizardBtn->setObjectName(QStringLiteral("wizardButton"));
    m_wizardBtn->setCursor(Qt::PointingHandCursor);
    m_wizardBtn->setVisible(false);
    root->addWidget(m_wizardBtn);

    root->addSpacing(8);
    root->addWidget(section(QStringLiteral("TEXTURE CACHE")));
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Enable Texture Cache"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        m_tcCheck = new QCheckBox;
        m_tcCheck->setObjectName(QStringLiteral("reinstallModeCheck"));
        lay->addWidget(lbl, 1);
        lay->addWidget(m_tcCheck);
        root->addWidget(row);
    }
    {
        auto *body = new QLabel(QStringLiteral(
            "The texture cache stores each texture once it is fully resolved (PSMT decode plus "
            "texture-pack replacement applied) in a single file. Later runs upload it directly: "
            "no VRAM hash match, no pack lookup and no PNG/DDS decode, which cuts texture CPU "
            "work. It fills progressively while you play and covers what you actually visit. It "
            "is rebuilt automatically when the pack or the Texture Replacement toggle changes."));
        body->setObjectName(QStringLiteral("hintLabel"));
        body->setWordWrap(true);
        root->addWidget(body);
    }
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        auto *lbl = new QLabel(QStringLiteral("Status"));
        lbl->setObjectName(QStringLiteral("valueLabel"));
        lbl->setMinimumWidth(110);
        m_tcStatus = new QLabel;
        m_tcStatus->setObjectName(QStringLiteral("hintLabel"));
        m_tcStatus->setWordWrap(true);
        lay->addWidget(lbl);
        lay->addWidget(m_tcStatus, 1);
        root->addWidget(row);
    }
    m_tcDelete = new QPushButton(QStringLiteral("Delete texture cache"), content);
    m_tcDelete->setObjectName(QStringLiteral("wizardButton"));
    m_tcDelete->setCursor(Qt::PointingHandCursor);
    root->addWidget(m_tcDelete);
    {
        auto *hint = new QLabel(QStringLiteral(
            "Deleting it only forces a rebuild on the next run; it does not touch the texture pack."));
        hint->setObjectName(QStringLiteral("hintLabel"));
        hint->setWordWrap(true);
        root->addWidget(hint);
    }

    root->addStretch(1);
    scroll->setWidget(content);

    auto *outer = new QVBoxLayout(this);
    outer->setContentsMargins(0, 0, 0, 0);
    outer->addWidget(scroll);

    connect(m_reinstall, &QCheckBox::toggled, this, &MiscTab::onReinstallMode);
    connect(m_wizardBtn, &QPushButton::clicked, this, &MiscTab::onInstallWizard);
    connect(m_browse, &QPushButton::clicked, this, &MiscTab::onOpenFolder);
    connect(m_tcDelete, &QPushButton::clicked, this, &MiscTab::onDeleteTexCache);
    connect(m_tcCheck, &QCheckBox::toggled, this, &MiscTab::onTexCacheToggled);

    refresh();
}

void MiscTab::refresh()
{
    const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
    const DiscVerify::State st = DiscVerify::verifyInstalledData(dataDir);

    m_size->setText(fmtSize(DiscVerify::dataSize(dataDir)));

    QString color;
    QString text;
    switch (st)
    {
    case DiscVerify::State::Valid:
        color = QStringLiteral("#22c55e");
        text = QStringLiteral("Installed and validated");
        break;
    case DiscVerify::State::Missing:
        color = QStringLiteral("#ef4444");
        text = QStringLiteral("Missing");
        break;
    case DiscVerify::State::Corrupt:
        color = QStringLiteral("#ef4444");
        text = QStringLiteral("Corrupted - reinstall required");
        break;
    }
    m_dot->setStyleSheet(QStringLiteral("font-size: 15px; color: %1;").arg(color));
    m_dotText->setText(text);

    // [texcache] enable checkbox + file status (built size, or not built yet).
    if (m_tcCheck)
    {
        QSignalBlocker block(m_tcCheck);
        m_tcCheck->setChecked(SettingsManager::instance().texcache());
    }
    if (m_tcStatus)
    {
        const QFileInfo fi(apppaths::userRoot() + QStringLiteral("/data/texcache.bin"));
        if (fi.exists())
            m_tcStatus->setText(QStringLiteral("Built - %1 MB").arg(fi.size() / (1024 * 1024)));
        else
            m_tcStatus->setText(QStringLiteral("Not built yet (fills on the next run)"));
        m_tcDelete->setEnabled(fi.exists());
    }

    m_reinstall->setChecked(m_reinstall->isChecked());
    m_wizardBtn->setVisible(m_reinstall->isChecked());
}

void MiscTab::onReinstallMode(bool on)
{
    m_wizardBtn->setVisible(on);
}

void MiscTab::onInstallWizard()
{
    auto *view = new InstallWizardView(nullptr, /*reinstall=*/true);
    view->onFinished = [this, view](bool) {
        view->deleteLater();
        viewhost::pop();
        refresh();
    };
    viewhost::show(view);
}

void MiscTab::onOpenFolder()
{
    const QString dataDir = apppaths::userRoot() + QStringLiteral("/data");
    const QString target = QDir(dataDir).exists() ? dataDir : apppaths::userRoot();
    if (!QDir().mkpath(target))
        return;
    QDesktopServices::openUrl(QUrl::fromLocalFile(target));
}

void MiscTab::onTexCacheToggled(bool on)
{
    SettingsManager::instance().setTexcache(on);
}

void MiscTab::onDeleteTexCache()
{
    // [texcache] Delete the cache file: the runner rebuilds it on the next launch.
    const QString tc = apppaths::userRoot() + QStringLiteral("/data/texcache.bin");
    QFile::remove(tc);
    QFile::remove(tc + QStringLiteral(".tmp"));
    refresh();
}
