#pragma once

#include <QObject>
#include <QString>

// Streams the validated disc image tree into the deployment data/ folder on a
// worker thread so the UI keeps painting the progress bar.
class ExtractWorker : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;

public slots:
    void doWork(const QString &isoPath, const QString &dataDir);

signals:
    void progress(qint64 done, qint64 total);
    void done(bool ok, const QString &msg);
};