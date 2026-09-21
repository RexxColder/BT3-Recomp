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
#include <QMessageBox>
#include <QPushButton>
#include <QTabWidget>
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

    m_tabs = new QTabWidget(this);
    m_bindings = new BindingsTab;
    m_tabs->addTab(new AudioTab, QStringLiteral("Audio"));
    m_tabs->addTab(new VideoTab, QStringLiteral("Video"));
    m_tabs->addTab(new ControllersTab(&m_bindings->players()), QStringLiteral("Controllers"));
    m_tabs->addTab(m_bindings, QStringLiteral("Bindings"));
    m_tabs->addTab(new LoggingTab, QStringLiteral("Logging"));
    m_tabs->addTab(new MiscTab, QStringLiteral("Misc"));
    m_tabs->addTab(new AboutTab, QStringLiteral("About"));
    layout->addWidget(m_tabs, 1);

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

    for (int i = 0; i < m_tabs->count(); ++i)
    {
        if (auto *b = qobject_cast<BindingsTab *>(m_tabs->widget(i)))
            b->load();
    }
    for (int i = 0; i < m_tabs->count(); ++i)
    {
        if (auto *c = qobject_cast<ControllersTab *>(m_tabs->widget(i)))
            c->syncFromPads();
    }
}

void SettingsView::onSave()
{
    for (int i = 0; i < m_tabs->count(); ++i)
    {
        if (auto *b = qobject_cast<BindingsTab *>(m_tabs->widget(i)))
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
