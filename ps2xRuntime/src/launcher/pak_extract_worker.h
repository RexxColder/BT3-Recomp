#pragma once

#include <QObject>
#include <QStringList>

// [pakunpack] Unpacks every .pak in the list into <pakdir>/<stem>/ (+ #info.idx),
// using the paklist.txt name DB from the bundled assets. Runs on a worker thread;
// the source .pak is kept (the runtime still serves it as a blob). status()
// carries the "what am I doing now" line shown under the progress bar.
class PakExtractWorker : public QObject
{
    Q_OBJECT
public:
    using QObject::QObject;

public slots:
    void doWork(const QStringList &pakFiles);

signals:
    void status(const QString &text);
    void progress(qint64 done, qint64 total);
    void done(bool ok, const QString &msg);
};
