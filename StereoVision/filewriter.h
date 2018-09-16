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
    void sendJobDone();

public slots:
    void receiveFrame(cv::Mat frame);
    void receiveStartWriting();
    void receiveStopWriting();
    void receiveSetSavePath(QString path);
    void receiveFrameSize(cv::Size size);

protected:
    QString savePath;
    void virtual executeReceiveFrame(cv::Mat frame)=0;
    void virtual executeReceiveStartWriting();
    void virtual executeReceiveStopWriting();
    void virtual executeReceiveFrameSize(cv::Size);

};

#endif // FILEWRITER_H
