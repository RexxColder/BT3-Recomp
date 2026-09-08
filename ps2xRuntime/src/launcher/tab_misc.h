#pragma once

#include <QWidget>

class QCheckBox;
class QLabel;
class QPushButton;

// "Misc" settings tab: shows the installed game data status (size + validity
// dot) and a Reinstall Mode toggle that exposes the Install Wizard.
class MiscTab : public QWidget
{
    Q_OBJECT
public:
    explicit MiscTab(QWidget *parent = nullptr);
    void refresh();

private slots:
    void onReinstallMode(bool on);
    void onInstallWizard();
    void onOpenFolder();

private:
    QLabel *m_size = nullptr;
    QLabel *m_dot = nullptr;
    QLabel *m_dotText = nullptr;
    QCheckBox *m_reinstall = nullptr;
    QPushButton *m_wizardBtn = nullptr;
    QPushButton *m_browse = nullptr;
};