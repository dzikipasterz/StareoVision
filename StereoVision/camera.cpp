#include "camera.h"

camera::camera(QObject *parent) :
    QObject(parent),
    status(true)
{
    cap = new cv::VideoCapture();
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
