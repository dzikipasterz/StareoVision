#ifndef VIDEOWRITER_H
#define VIDEOWRITER_H

#include <QObject>
#include <QDateTime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class VideoWriter : public QObject
{
    Q_OBJECT
public:
    explicit VideoWriter(QString path);
    ~VideoWriter();

signals:
    void sendMovFilePath(QString path);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveStartRecording();
    void receiveStopRecording();

private:
    QString savePath;
    cv::VideoWriter *leftCap;
    cv::VideoWriter *rightCap;
    bool recordFlag;
    cv::Size frameSize;

    void releaseWriter();
};

#endif // VIDEOWRITER_H
