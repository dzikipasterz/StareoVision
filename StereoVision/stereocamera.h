#ifndef STEREOCAMERA_H
#define STEREOCAMERA_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QObject>
#include <camera.h>



enum cameraMode {singleFrames, doubleFrames};

class stereoCamera : public QObject
{
    Q_OBJECT
public:
    explicit stereoCamera(cameraMode mode);
    ~stereoCamera();

signals:
    void sendCameraStatus(bool leftCamStatus, bool rightCamStatus);
    void sendFrames(cv::Mat leftFrame, cv::Mat rightFrame);
    void sendLeftFrame(cv::Mat frame);
    void sendRightFrame(cv::Mat frame);
    void sendJobDone();
    void sendRetrySetup();

public slots:
    void receiveGrabFrame();
    void receiveSetup(const int leftCameraId, const int rightCameraId);
private slots:
    void receiveRetrySetup();

private:
    int leftCameraDeviceId;
    int rightCameraDeviceId;
    camera * leftCamera;
    camera * rightCamera;
    bool retryFlag;
    cameraMode framesMode;

};
#endif // STEREOCAMERA_H
