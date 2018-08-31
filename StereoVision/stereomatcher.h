#ifndef STEREOMATCHER_H
#define STEREOMATCHER_H

#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

class StereoMatcher : public QObject
{
    Q_OBJECT
public:
    explicit StereoMatcher(QObject *parent = nullptr);

    void setCalibFile(QString file);

signals:
    void sendDisparityMap(cv::Mat disparity);

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

protected:
    QString calibrationFile;
    cv::Rect roi1, roi2;

    void virtual processFrames(cv::Mat leftFrame, cv::Mat rightFrame);

private:
    void readCalibFile();

};

#endif // STEREOMATCHER_H
