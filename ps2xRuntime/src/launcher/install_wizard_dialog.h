#pragma once

#include <QDialog>

class QLabel;
class QProgressBar;
class QPushButton;
class QStackedWidget;
class QThread;
class QTemporaryDir;
class ExtractWorker;

// End-user install wizard: detects missing/corrupt game data, lets the user
// point at their own disc dump (ISO or a container that wraps the ISO) and,
// after the embedded SHA-256 of SLUS_216.78 matches, extracts the game data
// tree into the deployment folder so the runner can boot it.
class InstallWizardDialog : public QDialog
{
    Q_OBJECT
public:
    explicit InstallWizardDialog(QWidget *parent = nullptr, bool reinstall = false);
    ~InstallWizardDialog() override;

    bool installed() const { return m_installed; }

private slots:
    void onNextMissing();
    void onBrowse();
    void onRetryDump();
    void onInstall();
    void onRetryInstall();
    void onExtractProgress(qint64 done, qint64 total);
    void onExtractDone(bool ok, const QString &msg);

private:
    void buildUi();
    void setIndex(int index);
    void setVerified(bool ok, const QString &text);
    void attemptVerify(const QString &dumpPath);
    // Unwraps a container (.rar/.7z/.zip/.tar...) and returns the inner disc
    // image path, or an empty string. On failure err holds the user message.
    QString resolveInnerImage(const QString &dumpPath, QString *err);
    void startExtraction();

    QStackedWidget *m_stack = nullptr;

    QPushButton *m_nextMissing = nullptr; // page A
    QLabel *m_selected = nullptr;         // page B
    QPushButton *m_browse = nullptr;
    QLabel *m_dot = nullptr;
    QLabel *m_dotText = nullptr;
    QPushButton *m_nextDump = nullptr;
    QPushButton *m_retryDump = nullptr;

    QLabel *m_progressText = nullptr; // page C
    QProgressBar *m_bar = nullptr;
    QLabel *m_doneLabel = nullptr;
    QPushButton *m_close = nullptr;
    QPushButton *m_retryInstall = nullptr;

    QTemporaryDir *m_tmp = nullptr;
    QString m_dumpPath;
    QString m_isoPath; // verified image ready for extraction
    bool m_verified = false;
    bool m_installed = false;

    QThread *m_thread = nullptr;
    ExtractWorker *m_worker = nullptr;
};