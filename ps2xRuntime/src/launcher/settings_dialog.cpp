#include "settings_dialog.h"

#include "dbz_theme.h"
#include "settings_manager.h"
#include "tab_about.h"
#include "tab_audio.h"
#include "tab_bindings.h"
#include "tab_controllers.h"
#include "tab_logging.h"
#include "tab_misc.h"
#include "tab_video.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QStackedWidget>
#include <QVBoxLayout>

SettingsView::SettingsView(QWidget *parent)
    : QWidget(parent)
{
    // [inwindow] Fills the launcher window (opaque, so it covers the launcher
    // background/bottom bar while shown).
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(QStringLiteral("SettingsView { background-color: #0a1014; }"));

    const QString fam = dbz::hudFontFamily();
    if (!fam.isEmpty())
    {
        QFont f(fam);
        f.setPointSizeF(f.pointSizeF() > 0.0 ? f.pointSizeF() : 11.0);
        setFont(f);
    }

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(14, 14, 14, 12);
    layout->setSpacing(10);

    // [sidebar] Left list + stacked pages (was a QTabWidget).
    auto *body = new QHBoxLayout;
    body->setSpacing(14);
    m_side = new QListWidget(this);
    m_side->setObjectName(QStringLiteral("settingsSidebar"));
    m_side->setFixedWidth(190);
    m_side->setFocusPolicy(Qt::NoFocus);
    m_side->setStyleSheet(QStringLiteral(
        "QListWidget#settingsSidebar { background: #0e141b; border: 1px solid #1e2830;"
        " border-radius: 6px; outline: 0; padding: 6px; }"
        "QListWidget#settingsSidebar::item { color: #c9ccd4; padding: 8px 10px; border-radius: 4px; }"
        "QListWidget#settingsSidebar::item:selected { background: rgba(255,158,26,0.16); color: #ffd9a0; }"
        "QListWidget#settingsSidebar::item:hover:!selected { background: rgba(255,158,26,0.08); }"));
    m_pages = new QStackedWidget(this);

    auto addPage = [&](QWidget *w, const QString &name) {
        m_side->addItem(name);
        m_pages->addWidget(w);
    };
    m_bindings = new BindingsTab;
    addPage(new AudioTab, QStringLiteral("Audio"));
    addPage(new VideoTab, QStringLiteral("Video"));
    addPage(new ControllersTab(&m_bindings->players()), QStringLiteral("Controllers"));
    addPage(m_bindings, QStringLiteral("Bindings"));
    addPage(new LoggingTab, QStringLiteral("Logging"));
    addPage(new MiscTab, QStringLiteral("Misc"));
    addPage(new AboutTab, QStringLiteral("About"));

    connect(m_side, &QListWidget::currentRowChanged, m_pages, &QStackedWidget::setCurrentIndex);
    m_side->setCurrentRow(0);

    body->addWidget(m_side);
    body->addWidget(m_pages, 1);
    layout->addLayout(body, 1);

    auto *buttonRow = new QWidget;
    auto *buttonLay = new QHBoxLayout(buttonRow);
    buttonLay->setContentsMargins(0, 0, 0, 0);
    buttonLay->addStretch(1);

    auto *cancel = new QPushButton(QStringLiteral("Back"));
    cancel->setObjectName(QStringLiteral("dialogButton"));
    connect(cancel, &QPushButton::clicked, this, &SettingsView::onClose);
    buttonLay->addWidget(cancel);

    auto *save = new QPushButton(QStringLiteral("Save Changes"));
    save->setObjectName(QStringLiteral("saveButton"));
    connect(save, &QPushButton::clicked, this, &SettingsView::onSave);
    buttonLay->addWidget(save);

    layout->addWidget(buttonRow);

    // Bindings load on open (pad.conf may be edited while the game runs).
    for (int i = 0; i < m_pages->count(); ++i)
    {
        if (auto *b = qobject_cast<BindingsTab *>(m_pages->widget(i)))
            b->load();
    }
    for (int i = 0; i < m_pages->count(); ++i)
    {
        if (auto *c = qobject_cast<ControllersTab *>(m_pages->widget(i)))
            c->syncFromPads();
    }
}

void SettingsView::onSave()
{
    for (int i = 0; i < m_pages->count(); ++i)
    {
        if (auto *b = qobject_cast<BindingsTab *>(m_pages->widget(i)))
            if (!b->save())
                QMessageBox::warning(this, QStringLiteral("Bindings"),
                    QStringLiteral("Could not write pad.conf (check permissions on the game folder)."));
    }
    SettingsManager::instance().save();
    if (onBack)
        onBack();
}

void SettingsView::onClose()
{
    if (onBack)
        onBack();
}
