#ifndef CORNERSFINDER_H
#define CORNERSFINDER_H

#include <QObject>
#include <QLabel>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class CornersFinder
{
public:
    CornersFinder();

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

signals:
    void sendProcessedFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void sendJobDone();


private:
};

#endif // CORNERSFINDER_H
