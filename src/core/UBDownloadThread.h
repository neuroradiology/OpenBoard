/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef UBDOWNLOADTHREAD_H
#define UBDOWNLOADTHREAD_H

#include <QThread>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class UBDownloadThread : public QThread
{
    Q_OBJECT
public:
    UBDownloadThread(QObject* parent=0, const char* name="UBDownloadThread");
    ~UBDownloadThread();
    void stopDownload();
    void startDownload(int id, QString url);

signals:
    void downloadFinised(int id);
    void downloadProgress(int id, qint64 current, qint64 total);

protected:
    virtual void run();

private slots:
    void onDownloadProgress(qint64 received, qint64 total);
    void onDownloadFinished();

private:
    /** Flag used to stop the thread */
    bool mbRun;
    /** The downloaded file id */
    int mID;
    /** The downloaded file url */
    QString mUrl;
    /** The network access manager */
    QNetworkAccessManager* mpNam;
    /** The network reply */
    QNetworkReply* mpReply;
};

#endif // UBDOWNLOADTHREAD_H
