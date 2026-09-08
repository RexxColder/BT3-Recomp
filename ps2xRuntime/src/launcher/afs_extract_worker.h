#pragma once

#include <QObject>
#include <QStringList>

// Converts every PZS3US*.AFS next to a data/ directory into folder slots +
// .idx and removes the source. Runs on a worker thread so the UI keeps
// painting the live progress; status() carries the "what am I doing right
// now" line shown under the progress bar.
class AfsExtractWorker : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;

public slots:
    void doWork(const QStringList &afsFiles);

signals:
    void status(const QString &text);
    void progress(qint64 done, qint64 total);
    void done(bool ok, const QString &msg);
};