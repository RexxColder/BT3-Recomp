#include "settings_dialog.h"

#include "dbz_theme.h"
#include "settings_manager.h"
#include "tab_audio.h"
#include "tab_bindings.h"
#include "tab_controllers.h"
#include "tab_logging.h"
#include "tab_misc.h"
#include "tab_video.h"

#include <QCloseEvent>
#include <QDialogButtonBox>
#include <QEasingCurve>
#include <QGraphicsOpacityEffect>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QPushButton>
#include <QShowEvent>
#include <QTabWidget>
#include <QVBoxLayout>

SettingsDialog::SettingsDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(QStringLiteral("Settings"));
    setModal(true);
    setAttribute(Qt::WA_StyledBackground, true);
    setStyleSheet(QStringLiteral(
        "SettingsDialog { background-color: %1; border: 2px solid #ff9e1a; border-radius: 8px; }")
        .arg(QLatin1String("#0a1014")));
    resize(660, 560);

    // Use the asset font (Russo One) if it was loaded by the app.
    const QString fam = dbz::hudFontFamily();
    if (!fam.isEmpty())
    {
        QFont f(fam);
        f.setPointSizeF(f.pointSizeF() > 0.0 ? f.pointSizeF() : 11.0);
        setFont(f);
    }

    // Fade-in/out entrance animation.
    m_fx = new QGraphicsOpacityEffect(this);
    m_fx->setOpacity(0.0);
    setGraphicsEffect(m_fx);
    m_anim = new QPropertyAnimation(m_fx, "opacity", this);
    m_anim->setDuration(200);
    m_anim->setEasingCurve(QEasingCurve::OutCubic);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(14, 14, 14, 12);
    layout->setSpacing(10);

    // Multi-tab: Audio / Video / Controllers / Bindings / Logging.
    // Controllers shares the per-player pad state with Bindings so a device
    // chosen there matches the Bindings tab's Auto/Keyboard/Gamepad mapping.
    m_tabs = new QTabWidget(this);
    m_bindings = new BindingsTab;
    m_tabs->addTab(new AudioTab, QStringLiteral("Audio"));
    m_tabs->addTab(new VideoTab, QStringLiteral("Video"));
    m_tabs->addTab(new ControllersTab(&m_bindings->players()), QStringLiteral("Controllers"));
    m_tabs->addTab(m_bindings, QStringLiteral("Bindings"));
    m_tabs->addTab(new LoggingTab, QStringLiteral("Logging"));
    m_tabs->addTab(new MiscTab, QStringLiteral("Misc"));
    // Video/Controllers/Logging live-write into SettingsManager; load() the
    // INI once via the singleton constructor call pattern (see main.cpp).
    layout->addWidget(m_tabs, 1);

    auto *buttonRow = new QWidget;
    auto *buttonLay = new QHBoxLayout(buttonRow);
    buttonLay->setContentsMargins(0, 0, 0, 0);
    buttonLay->addStretch(1);

    auto *cancel = new QPushButton(QStringLiteral("Cancel"));
    cancel->setObjectName(QStringLiteral("dialogButton"));
    connect(cancel, &QPushButton::clicked, this, &SettingsDialog::onClose);
    buttonLay->addWidget(cancel);

    auto *save = new QPushButton(QStringLiteral("Save Changes"));
    save->setObjectName(QStringLiteral("saveButton"));
    connect(save, &QPushButton::clicked, this, &SettingsDialog::onSave);
    buttonLay->addWidget(save);

    layout->addWidget(buttonRow);

    // Bindings load on open (pad.conf may be edited while the game runs).
    for (int i = 0; i < m_tabs->count(); ++i)
    {
        auto *b = qobject_cast<BindingsTab *>(m_tabs->widget(i));
        if (b)
            b->load();
    }
    // Controllers reads the same shared pad state; sync its device combo now
    // that pad.conf has been loaded.
    for (int i = 0; i < m_tabs->count(); ++i)
    {
        auto *c = qobject_cast<ControllersTab *>(m_tabs->widget(i));
        if (c)
            c->syncFromPads();
    }
}

void SettingsDialog::showEvent(QShowEvent *e)
{
    QDialog::showEvent(e);
    m_anim->setDuration(200);
    m_anim->setEasingCurve(QEasingCurve::OutCubic);
    m_anim->setStartValue(0.0);
    m_anim->setEndValue(1.0);
    // Drop the graphics effect once the fade-in finishes: keeping it forced a
    // render-to-pixmap on every repaint, which is what made the dialog laggy
    // while the ControllersTab polls at 60 fps.
    if (m_animClosing)
    {
        setGraphicsEffect(m_fx);
        m_fx->setOpacity(1.0);
        m_animClosing = false;
    }
    connect(m_anim, &QPropertyAnimation::finished, this, [this] {
        if (!m_animClosing && graphicsEffect() == m_fx)
            setGraphicsEffect(nullptr);
    }, Qt::UniqueConnection);
    m_anim->start();
}

void SettingsDialog::closeEvent(QCloseEvent *e)
{
    if (m_animClosing)
    {
        QDialog::closeEvent(e);
        return;
    }
    // Trigger the fade-out animation, then really close.
    e->ignore();
    m_animClosing = true;
    setGraphicsEffect(m_fx);
    m_fx->setOpacity(1.0);
    m_anim->setDuration(150);
    m_anim->setEasingCurve(QEasingCurve::InCubic);
    m_anim->setStartValue(1.0);
    m_anim->setEndValue(0.0);
    connect(m_anim, &QPropertyAnimation::finished, this, [this] {
        reject();
    }, Qt::UniqueConnection);
    m_anim->start();
}

void SettingsDialog::onSave()
{
    for (int i = 0; i < m_tabs->count(); ++i)
    {
        if (auto *b = qobject_cast<BindingsTab *>(m_tabs->widget(i)))
            if (!b->save())
                QMessageBox::warning(this, QStringLiteral("Bindings"),
                    QStringLiteral("Could not write pad.conf (check permissions on the game folder)."));
    }
    SettingsManager::instance().save();
    accept();
}

void SettingsDialog::onClose()
{
    close();
}