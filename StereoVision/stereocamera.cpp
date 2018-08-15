#include "stereocamera.h"

stereoCamera::stereoCamera(QObject *parent) :
    QObject(parent)
{
    leftCamera = new camera();
    rightCamera = new camera();
}

stereoCamera::~stereoCamera()
{
    leftCamera->~camera();
    rightCamera->~camera();
    delete leftCamera;
    delete rightCamera;
}

void stereoCamera::receiveSetup(const int leftCameraId, const int rightCameraId)
{
    bool leftCameraStatus = leftCamera->setDevice(leftCameraId);
    bool rightCameraStatus = rightCamera->setDevice(rightCameraId);
    emit sendCameraStatus(leftCameraStatus, rightCameraStatus);
}

void stereoCamera::receiveGrabFrame()
{
    cv::Mat leftFrame = leftCamera->grabFrame();
    cv::Mat rightFrame = rightCamera->grabFrame();
    if(!(leftFrame.empty() && rightFrame.empty()))
            emit sendFrames(leftFrame, rightFrame);
    emit sendJobDone();
}
