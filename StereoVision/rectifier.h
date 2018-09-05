#ifndef UNDISTORTMAPPER_H
#define UNDISTORTMAPPER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv_modules.hpp>

class Rectifier : public QObject
{
    Q_OBJECT
public:
    explicit Rectifier(QObject *parent = nullptr);

    void setCalibrationFile(QString filename);

signals:
    void sendFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

private:
    QString calibrationFile;
    cv::Mat leftMap1;
    cv::Mat leftMap2;
    cv::Mat rightMap1;
    cv::Mat rightMap2;
    cv::Ptr<cv::CLAHE> clahe;

    void readCalibFile();
};

#endif // UNDISTORTMAPPER_H
