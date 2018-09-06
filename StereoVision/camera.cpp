#include "camera.h"

camera::camera(QObject *parent) :
    QObject(parent),
    status(true)
{
    cap = new cv::VideoCapture();
    cap->set(CV_CAP_PROP_FRAME_WIDTH,1920);
    cap->set(CV_CAP_PROP_FRAME_HEIGHT, 1080);
}

camera::~camera()
{
    closeDevice();
    delete cap;
}

void camera::openDevice(const int device)
{
    closeDevice();
    cap->open(device);
}

void camera::closeDevice()
{
    if(cap->isOpened()) cap->release();
}

cv::Mat camera::grabFrame()
{
    cv::Mat emptyFrame;

    if(!status)
    {
        (*cap) >> frame;
        return frame;
    }
    else return emptyFrame;
}

bool camera::setDevice(const int device)
{
    openDevice(device);
    if(!cap->isOpened()) {
        status=true;
    }
    else
    {
        status=false;
    }

    return status;
}
