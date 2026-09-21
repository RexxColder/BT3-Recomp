#pragma once

#include <QMainWindow>
#include <QString>

class QLabel;
class QPushButton;
class QProcess;
class QWidget;
class QStackedWidget;
class QGraphicsDropShadowEffect;
class QPropertyAnimation;

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
    void showEvent(QShowEvent *) override;

private:
    void loadBackground();
    void resolveLaunchTarget();
    void updateHint();
    void checkGameData();
    void openInstallWizard();
    // [inwindow] Swap the whole window content for a view (settings, wizard, ...)
    // and back to the launcher page.
    void showView(QWidget *view);
    void showLauncher();
    void popView();
    // [vulkan] Windows: append a line to logs/vulkan-fallback.log so the
    // auto-fallback (vendor Vulkan driver crash -> OpenGL) is diagnosable.
    void logVulkanFallback(const QString &msg);
    // [firstboot] pulse the SETTINGS button until the user opens it, so a
    // first-time user (no settings.toml yet) is drawn to Settings > Misc.
    void startSettingsGlow();
    void stopSettingsGlow();
    // [glow] soft orange halo that pulses forever. PLAY uses it whenever the
    // button is enabled; SETTINGS only on first boot.
    void setButtonGlow(QPushButton *btn, QGraphicsDropShadowEffect *&fx,
                       QPropertyAnimation *&anim, bool on);

    QLabel *m_hint = nullptr;
    QLabel *m_specs = nullptr;   // [hwprobe] detected hardware banner (bottom-left)
    QStackedWidget *m_stack = nullptr;   // [inwindow] page 0 = launcher, others = views
    QPushButton *m_play = nullptr;
    QPushButton *m_settings = nullptr;
    QWidget *m_bottomBar = nullptr;
    QProcess *m_gameProc = nullptr;

    QString m_gameElf;
    QString m_bgPath;
    QString m_savedataDir;
    QString m_dataDir;
    bool m_plainRunner = false;
    bool m_gameDataValid = false;
    bool m_wizardShown = false;
    bool m_fallbackRetried = false;   // [vulkan] Windows: retry OpenGL at most once
    QGraphicsDropShadowEffect *m_settingsGlow = nullptr;
    QPropertyAnimation *m_settingsGlowAnim = nullptr;
    QGraphicsDropShadowEffect *m_playGlow = nullptr;
    QPropertyAnimation *m_playGlowAnim = nullptr;
};