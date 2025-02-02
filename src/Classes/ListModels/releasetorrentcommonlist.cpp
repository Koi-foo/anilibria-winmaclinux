#include <QUrl>
#include <QDesktopServices>
#include "releasetorrentcommonlist.h"
#include "../../globalconstants.h"

ReleaseTorrentCommonList::ReleaseTorrentCommonList(QObject *parent)
    : QAbstractListModel{parent}
{
    connect(m_networkManager.get(), &QNetworkAccessManager::finished, this, &ReleaseTorrentCommonList::downloadTorrentResponse);
}

int ReleaseTorrentCommonList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;

    return m_torrents->size();
}

QVariant ReleaseTorrentCommonList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    auto torrent = m_torrents->at(index.row());

    switch (role) {
        case IdRole: {
            return QVariant(torrent->id());
        }
        case SizeRole: {
            return QVariant(getReadableSize(torrent->size()));
        }
        case QualityRole: {
            return QVariant(torrent->quality());
        }
        case SeriesRole: {
            return QVariant(torrent->series());
        }
        case UrlRole: {
            return QVariant(torrent->url());
        }
        case IndexRole: {
            return QVariant(index.row());
        }
    }

    return QVariant();
}

QHash<int, QByteArray> ReleaseTorrentCommonList::roleNames() const
{
    return {
        {
            IdRole,
            "id"
        },
        {
            SizeRole,
            "size"
        },
        {
            QualityRole,
            "quality"
        },
        {
            SeriesRole,
            "series"
        },
        {
            UrlRole,
            "url"
        },
        {
            IndexRole,
            "currentIndex"
        }
    };
}

void ReleaseTorrentCommonList::loadFromJson(const QString &json)
{
    beginResetModel();

    m_torrents->clear();

    if (json.isEmpty()) return;

    auto jsonDocument = QJsonDocument::fromJson(json.toUtf8());
    auto jsonArray = jsonDocument.array();
    foreach (auto item, jsonArray) {
        auto torrent = new ReleaseTorrentModel();
        torrent->readFromApiModel(item.toObject());
        m_torrents->append(torrent);
    }

    endResetModel();
}

void ReleaseTorrentCommonList::downloadTorrent(const int index)
{
    auto torrent = m_torrents->at(index);
    QNetworkRequest request(QUrl(AnilibriaImagesPath + torrent->url()));

    m_networkManager->get(request);
}

QString ReleaseTorrentCommonList::getReadableSize(long long size) const noexcept
{
    QList<QString> sizes;
    sizes.append("B");
    sizes.append("KB");
    sizes.append("MB");
    sizes.append("GB");
    sizes.append("TB");

    int order = 0;
    while (size >= 1024 && order < 4) {
        order++;
        size = size / 1024;
    }

    auto stringSize = QString::number(size);
    QString result;
    result.append(stringSize);
    result.append(" ");
    result.append(sizes[order]);
    return result;
}

void ReleaseTorrentCommonList::downloadTorrentResponse(QNetworkReply *reply)
{
    auto status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if (status_code.isValid()){
        auto code = status_code.toInt();
        if (code != 200) {
            emit failureDownloadTorrent();
            return;
        }
    }

    auto byteArray = reply->readAll();
    if (byteArray.size() == 0) {
        emit failureDownloadTorrent();
        return;
    }

    auto uuid = QUuid::createUuid();
    auto randomName = uuid.toString().replace("-", "").replace("{", "").replace("}", "").replace("[", "").replace("]", "");
    auto randomTorrentPath = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/" + randomName + ".torrent";
    QFile torrentFile(randomTorrentPath);
    torrentFile.open(QFile::WriteOnly);
    torrentFile.write(byteArray);
    torrentFile.close();

#ifdef Q_OS_WIN
    QDesktopServices::openUrl("file:///" + randomTorrentPath);
#else
    QDesktopServices::openUrl("file://" + randomTorrentPath);
#endif
}
