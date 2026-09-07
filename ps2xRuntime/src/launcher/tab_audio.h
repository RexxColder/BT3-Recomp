#pragma once

#include <QWidget>

class QSlider;
class QLabel;

class AudioTab : public QWidget
{
    Q_OBJECT
public:
    explicit AudioTab(QWidget *parent = nullptr);

private:
    QSlider *m_master = nullptr;
    QSlider *m_music = nullptr;
    QSlider *m_sfx = nullptr;
    QLabel *m_masterVal = nullptr;
    QLabel *m_musicVal = nullptr;
    QLabel *m_sfxVal = nullptr;

    void onChanged();
};