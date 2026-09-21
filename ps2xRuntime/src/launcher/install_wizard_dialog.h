#pragma once

#include <QWidget>
#include <QElapsedTimer>
#include <atomic>
#include <functional>

#include "hardware_probe.h"

class QLabel;
class QProgressBar;
class QPushButton;
class QStackedWidget;
class QThread;
class QTemporaryDir;
class ExtractWorker;
class AfsExtractWorker;

// [inwindow] End-user install wizard as an in-window VIEW (not a popup): the launcher
// swaps its whole content for this widget. It detects missing/corrupt game data, lets
// the user point at their own disc dump, verifies the embedded SHA-256 of SLUS_216.78,
// extracts the game data tree, and returns via onFinished.
class InstallWizardView : public QWidget
{
    Q_OBJECT
public:
    explicit InstallWizardView(QWidget *parent = nullptr, bool reinstall = false);
    ~InstallWizardView() override;

    // [inwindow] Called when the wizard is done: accepted = installed OK.
    std::function<void(bool accepted)> onFinished;

    bool installed() const { return m_installed; }
    // [summary] Page D actions.
    bool playRequested() const { return m_playRequested; }
    bool openSettingsRequested() const { return m_openSettings; }

private slots:
    void onNextMissing();
    void onBrowse();
    void onRetryDump();
    void onInstall();
    void onRetryInstall();
    void onExtractProgress(qint64 done, qint64 total);
    void onExtractDone(bool ok, const QString &msg);
    void onAfsStatus(const QString &text);
    void onAfsProgress(qint64 done, qint64 total);
    void onAfsDone(bool ok, const QString &msg);

private:
    void buildUi();
    void setIndex(int index);
    void setVerified(bool ok, const QString &text);
    void attemptVerify(const QString &dumpPath);
    // Unwraps a container (.rar/.7z/.zip/.tar...) and returns the inner disc
    // image path, or an empty string. On failure err holds the user message.
    QString resolveInnerImage(const QString &dumpPath, QString *err);
    void startExtraction();
    // Second install phase: turn every extracted PZS3US*.AFS into folder slots
    // (+ .idx) and drop the container, leaving folders as the only data source.
    void startAfsConversion();
    void applyInstallResult(bool ok, const QString &msg);
    void finish(bool accepted);   // [inwindow] leave the view

    QStackedWidget *m_stack = nullptr;

    QPushButton *m_nextMissing = nullptr; // page A
    QLabel *m_selected = nullptr;         // page B
    QPushButton *m_browse = nullptr;
    QLabel *m_dot = nullptr;
    QLabel *m_dotText = nullptr;
    QPushButton *m_nextDump = nullptr;
    QPushButton *m_retryDump = nullptr;

    QLabel *m_progressText = nullptr;  // page C
    QProgressBar *m_bar = nullptr;
    QLabel *m_activity = nullptr;      // live "what is happening now" line
    QLabel *m_doneLabel = nullptr;
    QPushButton *m_close = nullptr;
    QPushButton *m_retryInstall = nullptr;

    // Page D: post-install summary + hardware + recommendation.
    QLabel *m_summary = nullptr;
    QLabel *m_hwLabel = nullptr;
    QLabel *m_recLabel = nullptr;
    QPushButton *m_openSettingsBtn = nullptr;
    QPushButton *m_playBtn = nullptr;
    QPushButton *m_applyBtn = nullptr;
    hw::Recommendation m_rec;   // [tier] computed on Page D, applied by m_applyBtn

    QTemporaryDir *m_tmp = nullptr;
    QString m_dumpPath;
    QString m_isoPath; // verified image ready for extraction
    bool m_reinstall = false;
    bool m_verified = false;
    bool m_installed = false;
    bool m_inAfsPhase = false; // retry re-runs the AFS phase only
    bool m_playRequested = false;
    bool m_openSettings = false;

    QThread *m_thread = nullptr;
    ExtractWorker *m_worker = nullptr;
    QThread *m_afsThread = nullptr;
    AfsExtractWorker *m_afsWorker = nullptr;
    QElapsedTimer m_timer;   // [verbose] for the ETA

    // [tier] silent single-thread benchmark, started when Page B is entered.
    hw::Info m_hw;
    std::atomic<double> m_cpuR{0.0};
    QThread *m_benchThread = nullptr;
};
