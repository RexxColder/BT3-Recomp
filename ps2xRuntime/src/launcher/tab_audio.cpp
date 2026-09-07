#include "tab_audio.h"

#include "settings_manager.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QVBoxLayout>

namespace
{
    QWidget *sliderRow(const QString &label, QSlider **sl, QLabel **val)
    {
        auto *row = new QWidget;
        auto *lay = new QHBoxLayout(row);
        lay->setContentsMargins(8, 2, 8, 2);
        lay->setSpacing(10);
        auto *lbl = new QLabel(label);
        lbl->setObjectName(QStringLiteral("valueLabel"));
        lbl->setMinimumWidth(60);
        *sl = new QSlider(Qt::Horizontal);
        (*sl)->setRange(0, 100);
        *val = new QLabel(QStringLiteral("100%"));
        (*val)->setObjectName(QStringLiteral("valueLabel"));
        (*val)->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        lay->addWidget(lbl);
        lay->addWidget(*sl, 1);
        lay->addWidget(*val);
        return row;
    }
} // namespace

AudioTab::AudioTab(QWidget *parent)
    : QWidget(parent)
{
    auto *root = new QVBoxLayout(this);
    root->setContentsMargins(18, 14, 18, 14);
    root->setSpacing(10);

    auto *masterLabel = new QLabel(QStringLiteral("MASTER VOLUME"));
    masterLabel->setObjectName(QStringLiteral("sectionLabel"));
    root->addWidget(masterLabel);
    auto *masterRow = sliderRow(QStringLiteral("Master"), &m_master, &m_masterVal);
    auto *gameLabel = new QLabel(QStringLiteral("MIXER"));
    gameLabel->setObjectName(QStringLiteral("sectionLabel"));
    root->addWidget(masterRow);
    root->addWidget(gameLabel);
    auto *musicRow = sliderRow(QStringLiteral("Music"), &m_music, &m_musicVal);
    auto *sfxRow = sliderRow(QStringLiteral("SFX"), &m_sfx, &m_sfxVal);
    root->addWidget(musicRow);
    root->addWidget(sfxRow);

    auto *hint = new QLabel(QStringLiteral(
        "Global output volume. Music = BGM streams. SFX = voices, effects and one-shots."));
    hint->setObjectName(QStringLiteral("hintLabel"));
    hint->setWordWrap(true);
    root->addWidget(hint);
    root->addStretch(1);

    auto &s = SettingsManager::instance();
    m_master->setValue(int(s.masterVolume() * 100.0f));
    m_music->setValue(int(s.musicVolume() * 100.0f));
    m_sfx->setValue(int(s.sfxVolume() * 100.0f));
    onChanged();

    connect(m_master, &QSlider::valueChanged, this, [this](int) { onChanged(); });
    connect(m_music, &QSlider::valueChanged, this, [this](int) { onChanged(); });
    connect(m_sfx, &QSlider::valueChanged, this, [this](int) { onChanged(); });
}

void AudioTab::onChanged()
{
    auto &s = SettingsManager::instance();
    s.setMasterVolume(m_master->value() / 100.0f);
    s.setMusicVolume(m_music->value() / 100.0f);
    s.setSfxVolume(m_sfx->value() / 100.0f);
    m_masterVal->setText(QString::number(m_master->value()) + QStringLiteral("%"));
    m_musicVal->setText(QString::number(m_music->value()) + QStringLiteral("%"));
    m_sfxVal->setText(QString::number(m_sfx->value()) + QStringLiteral("%"));
}