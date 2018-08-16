#include "stereocamera.h"

stereoCamera::stereoCamera(QObject *parent) :
    QObject(parent),
    retryFlag(false)
{
    leftCamera = new camera();
    rightCamera = new camera();
    //connect(this, SIGNAL(sendRetrySetup(const int, const int)), this, SLOT(receiveSetup(const int, const int)));
}

stereoCamera::~stereoCamera()
{
    delete leftCamera;
    delete rightCamera;
}

void stereoCamera::receiveSetup(const int leftCameraId, const int rightCameraId)
{
    if(retryFlag)
    {
        for(int j = 0; j<1000000000; j++){};
    }
    bool leftCameraStatus = leftCamera->setDevice(leftCameraId);
    bool rightCameraStatus = rightCamera->setDevice(rightCameraId);
    emit sendCameraStatus(leftCameraStatus, rightCameraStatus);

    if(leftCameraId || rightCameraId) retryFlag=true;
    else retryFlag=false;

}

void stereoCamera::receiveGrabFrame()
{
    cv::Mat leftFrame = leftCamera->grabFrame();
    cv::Mat rightFrame = rightCamera->grabFrame();
    if(!(leftFrame.empty() && rightFrame.empty()))
            emit sendFrames(leftFrame, rightFrame);
    emit sendJobDone();
}

