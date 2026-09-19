#include "app_paths.h"
#include "pak_extract_worker.h"

#include "pak_archive.h"

#include <QFileInfo>

void PakExtractWorker::doWork(const QStringList &pakFiles)
{
    qint64 totalBytes = 0;
    for (const QString &f : pakFiles)
        totalBytes += QFileInfo(f).size();
    if (totalBytes <= 0)
    {
        emit done(false, QStringLiteral("No PAK containers to unpack."));
        return;
    }

    const qint64 tickBytes = qMax<qint64>(256 * 1024, totalBytes / 1000); // ~0.1% UI throttle

    qint64 base = 0;
    for (const QString &f : pakFiles)
    {
        const QFileInfo info(f);
        const qint64 fileTotal = info.size();
        qint64 last = base;

        emit status(QStringLiteral("Unpacking %1…").arg(info.fileName()));

        const auto onStatus = [this](const std::string &s) {
            emit status(QString::fromStdString(s));
        };
        const auto onProgress = [this, &last, tickBytes, totalBytes, base](uint64_t d, uint64_t) {
            const qint64 cur = base + static_cast<qint64>(d);
            if (cur - last >= tickBytes)
            {
                last = cur;
                emit progress(cur, totalBytes);
            }
        };

        const PakConvertResult r = convertPakToFolder(
            f.toStdString(), info.absolutePath().toStdString(), onStatus, onProgress,
            apppaths::assets().toStdString());

        if (!r.ok)
        {
            emit progress(totalBytes, totalBytes);
            emit done(false, QString::fromStdString(r.error));
            return;
        }

        base += fileTotal;
        emit progress(base, totalBytes);
    }

    emit done(true, QString());
}
