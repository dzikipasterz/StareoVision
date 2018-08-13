#include "framegrabber.h"

frameGrabber::frameGrabber(QObject *parent) :
    QObject(parent),
    status(false)
{
    cap = new cv::VideoCapture();
}

frameGrabber::~frameGrabber()
{
    closeDevice();
}

void frameGrabber::openDevice(const int device)
{
    closeDevice();
    cap->open(device);
}

void frameGrabber::closeDevice()
{
    if(cap->isOpened()) cap->release();
}

void frameGrabber::receiveGrabFrame()
{
    (*cap) >> frame;
    if(frame.empty()) return;

    emit sendFrame(frame);
    emit sendJobDone();
}

void frameGrabber::receiveSetup(const int device)
{
    openDevice(device);
    if(!cap->isOpened()) {
        emit sendStatus(true);
    }
    else
    {
        emit sendStatus(false);
    }

    status = true;
}
