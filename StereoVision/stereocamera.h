#ifndef STEREOCAMERA_H
#define STEREOCAMERA_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QObject>
#include <camera.h>


class stereoCamera : public QObject
{
    Q_OBJECT
public:
    explicit stereoCamera(QObject *parent = nullptr);
    ~stereoCamera();

signals:
    void sendCameraStatus(bool leftCameraStatus, bool rightCameraStatus);
    void sendFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void sendJobDone();

public slots:
    void receiveGrabFrame();
    void receiveSetup(const int leftCameraId, const int rightCameraId);

private:
    camera * leftCamera;
    camera * rightCamera;
};
#endif // STEREOCAMERA_H
