#include "stereocamera.h"

stereoCamera::stereoCamera(cameraMode mode) :
    retryFlag(false)
{
    leftCamera = new camera();
    rightCamera = new camera();
    framesMode = mode;
    connect(this, SIGNAL(sendRetrySetup()), this, SLOT(receiveRetrySetup()), Qt::QueuedConnection);
}

stereoCamera::~stereoCamera()
{
    delete leftCamera;
    delete rightCamera;
}

void stereoCamera::receiveSetup(const int leftCameraId, const int rightCameraId)
{
    leftCameraDeviceId = leftCameraId;
    rightCameraDeviceId = rightCameraId;
    bool leftCameraStatus = leftCamera->setDevice(leftCameraDeviceId);
    bool rightCameraStatus = rightCamera->setDevice(rightCameraDeviceId);
    emit sendCameraStatus(leftCameraStatus, rightCameraStatus);

    if(leftCameraStatus || rightCameraStatus)
    {
        retryFlag = true;
        emit sendRetrySetup();
    }
    else retryFlag = false;
}

void stereoCamera::receiveRetrySetup()
{
    if(retryFlag)
    {
        bool leftCameraStatus = leftCamera->setDevice(leftCameraDeviceId);
        bool rightCameraStatus = rightCamera->setDevice(rightCameraDeviceId);
        emit sendCameraStatus(leftCameraStatus, rightCameraStatus);

        if(leftCameraStatus || rightCameraStatus)
        {
            for(int i = 0; i < 10000000; i++){};
            emit sendRetrySetup();
        }
        else retryFlag=false;
    }
}

void stereoCamera::receiveGrabFrame()
{
    cv::Mat leftFrame = leftCamera->grabFrame();
    cv::Mat rightFrame = rightCamera->grabFrame();
    if(!(leftFrame.empty() || rightFrame.empty()))
    {
        switch(framesMode)
        {
            case singleFrames:
                emit sendLeftFrame(leftFrame);
                emit sendRightFrame(rightFrame);
                break;

            case doubleFrames:
                emit sendFrames(leftFrame, rightFrame);
                break;
        }
    }
        emit sendJobDone();
}

