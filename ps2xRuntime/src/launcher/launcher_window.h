#pragma once

#include <QMainWindow>
#include <QString>

class QLabel;
class QPushButton;
class QProcess;
class QWidget;

class LauncherWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit LauncherWindow(QWidget *parent = nullptr);

    // Absolute path to the playable game ELF (self-extracting BT3SELFX binary)
    // found next to the launcher. Empty if none detected.
    static QString findGameElf();

private slots:
    void onPlayClicked();
    void onSettingsClicked();

protected:
    void paintEvent(QPaintEvent *) override;

private:
    void loadBackground();

    QLabel *m_hint = nullptr;
    QPushButton *m_play = nullptr;
    QPushButton *m_settings = nullptr;
    QWidget *m_bottomBar = nullptr;
    QString m_gameElf;
    QString m_bgPath;
    QProcess *m_gameProc = nullptr;

    QString m_savedataDir;
};