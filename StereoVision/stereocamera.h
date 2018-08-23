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
    void sendCameraStatus(bool leftCamStatus, bool rightCamStatus);
    void sendFrames(cv::Mat leftFrame, cv::Mat rightFrame);
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

};
#endif // STEREOCAMERA_H
