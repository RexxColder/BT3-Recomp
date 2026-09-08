#include "tab_logging.h"

#include "settings_manager.h"

#include <QCheckBox>
#include <QComboBox>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

static const char *kLevelDescriptions[4] = {
    // 0 = OFF
    "Everything is silent. No log files are written and the game runs with a "
    "perf-neutral console.",
    // 1 = Balanced (default)
    "Profile + mclog + scheduler events: launch stalls, save/load storms and "
    "frame pacing hiccups. Recommended for day-to-day play.",
    // 2 = Verbose
    "Adds per-frame GPU draws, memory-card traffic, audio voice state and pad "
    "events. Use when chasing a specific subsystem bug.",
    // 3 = Debug
    "Everything the runtime can emit (per-opcode recompiler, VU1 JIT, guest "
    "heap walks and raw VRAM dumps). Very slow; only for crash triage.",
};

LoggingTab::LoggingTab(QWidget *parent)
    : QWidget(parent)
{
    auto &s = SettingsManager::instance();

    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(18, 14, 18, 14);
    root->setSpacing(12);

    auto *onRow = new QWidget;
    auto *onLay = new QHBoxLayout(onRow);
    onLay->setContentsMargins(8, 2, 8, 2);
    auto *lbl = new QLabel(QStringLiteral("Enabled"));
    lbl->setObjectName(QStringLiteral("valueLabel"));
    m_enabled = new QCheckBox;
    m_enabled->setChecked(s.logLevel() > 0);
    onLay->addWidget(lbl, 1);
    onLay->addWidget(m_enabled);
    root->addWidget(onRow);

    auto *levelRow = new QWidget;
    auto *levelLay = new QHBoxLayout(levelRow);
    levelLay->setContentsMargins(8, 2, 8, 2);
    auto *ll = new QLabel(QStringLiteral("Level"));
    ll->setObjectName(QStringLiteral("valueLabel"));
    m_level = new QComboBox;
    m_level->addItems({QStringLiteral("OFF"), QStringLiteral("Balanced"),
                       QStringLiteral("Verbose"), QStringLiteral("Debug")});
    m_level->setCurrentIndex(s.logLevel());
    levelLay->addWidget(ll, 1);
    levelLay->addWidget(m_level, 0);
    m_level->setMinimumWidth(150);
    root->addWidget(levelRow);

    auto *line = new QFrame;
    line->setFrameShape(QFrame::HLine);
    line->setStyleSheet(QStringLiteral("QFrame { color: #2a3640; }"));
    root->addWidget(line);

    m_descTitle = new QLabel;
    m_descTitle->setObjectName(QStringLiteral("sectionLabel"));
    root->addWidget(m_descTitle);

    m_descBody = new QLabel;
    m_descBody->setObjectName(QStringLiteral("hintLabel"));
    m_descBody->setWordWrap(true);
    root->addWidget(m_descBody);

    auto *note = new QLabel(QStringLiteral(
        "Log files land in logs/bt3.log next to the game ELF. The share the "
        "level of the game's live overlay (Shift+Tab)."));
    note->setObjectName(QStringLiteral("hintLabel"));
    note->setWordWrap(true);
    root->addWidget(note);

    root->addStretch(1);

    connect(m_enabled, &QCheckBox::toggled, this, &LoggingTab::onToggle);
    connect(m_level, &QComboBox::currentIndexChanged, this, &LoggingTab::onLevel);
    updateDesc();
}

void LoggingTab::onToggle(bool on)
{
    if (on)
    {
        // Enable at the last seen level.
        SettingsManager::instance().setLogLevel(m_level->currentIndex());
    }
    else
    {
        SettingsManager::instance().setLogLevel(0);
    }
    updateDesc();
}

void LoggingTab::onLevel(int idx)
{
    (void)idx;
    SettingsManager::instance().setLogLevel(m_level->currentIndex());
    updateDesc();
}

void LoggingTab::updateDesc()
{
    const int eff = SettingsManager::instance().logLevel();
    if (eff == 0)
        m_descTitle->setText(QStringLiteral("Logging is OFF"));
    else if (eff == 1)
        m_descTitle->setText(QStringLiteral("Level 1 \u2014 Balanced"));
    else if (eff == 2)
        m_descTitle->setText(QStringLiteral("Level 2 \u2014 Verbose"));
    else if (eff == 3)
        m_descTitle->setText(QStringLiteral("Level 3 \u2014 Debug"));
    m_descBody->setText(QString::fromUtf8(kLevelDescriptions[eff]));
}