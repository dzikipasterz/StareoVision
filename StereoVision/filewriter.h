#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>

class FileWriter : public QObject
{
    Q_OBJECT
public:
    explicit FileWriter(QObject *parent = nullptr);

signals:
    void sendFilePath(QString path);

public slots:
    void receiveFrame(cv::Mat frame);
    void receiveStartWriting();
    void receiveStopWriting();
    void receiveSetSavePath(QString path);

protected:
    QString savePath;
    void virtual executeReceiveFrame(cv::Mat frame)=0;
    void virtual executeReceiveStartWriting();
    void virtual executeReceiveStopWriting();

};

#endif // FILEWRITER_H
