#pragma once

#include <QWidget>

class QCheckBox;
class QComboBox;
class QLabel;

// Redesigned Logging tab: master ON/OFF toggle + level selector (0-3) with a
// dynamic description panel, replacing the old dump-checkbox page. Maps to the
// runtime [logging] log_level (0=off silently via the toggle).
class LoggingTab : public QWidget
{
    Q_OBJECT
public:
    explicit LoggingTab(QWidget *parent = nullptr);

private slots:
    void onToggle(bool);
    void onLevel(int);

private:
    QCheckBox *m_enabled = nullptr;
    QComboBox *m_level = nullptr;
    QLabel *m_descTitle = nullptr;
    QLabel *m_descBody = nullptr;

    void updateDesc();
};