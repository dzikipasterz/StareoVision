#ifndef VIDEOWRITER_H
#define VIDEOWRITER_H

#include <QObject>
#include <QDateTime>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <filewriter.h>

class VideoWriter : public FileWriter
{
    Q_OBJECT
public:
    explicit VideoWriter(QString filePath);
    ~VideoWriter();

signals:
    void sendMovFilesPaths(QString leftPath, QString rightPath);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void receiveStartRecording();
    void receiveStopRecording();

protected:

private:
    QString savePath;
    cv::VideoWriter *leftCap;
    cv::VideoWriter *rightCap;
    bool recordFlag;
    cv::Size frameSize;

    void releaseWriter();
};

#endif // VIDEOWRITER_H
