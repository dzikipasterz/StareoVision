#ifndef STEREOMATCHER_H
#define STEREOMATCHER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/ximgproc/disparity_filter.hpp"

class StereoMatcher : public QObject
{
    Q_OBJECT
public:
    explicit StereoMatcher(QObject *parent = nullptr);

signals:
    void sendDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparity);
    void sendJobDone();

public slots:
    void receiveFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified);

protected:
    cv::Mat dispOut;
    void virtual process(cv::Mat lRect, cv::Mat rRect) = 0;

};

#endif // STEREOMATCHER_H
