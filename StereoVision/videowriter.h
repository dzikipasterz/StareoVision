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
    explicit VideoWriter();
    ~VideoWriter() override;

protected:
    void executeReceiveFrame(cv::Mat frame) override;
    void executeReceiveStartWriting() override;
    void executeReceiveStopWriting() override;
    void executeReceiveFrameSize(cv::Size size) override;

signals:
    void sendOpenRetry();

private slots:
    void receiveOpenRetry();

private:
    cv::VideoWriter *cap;
    bool recordFlag;
    cv::Size frameSize;

    void releaseWriter();
};

#endif // VIDEOWRITER_H
