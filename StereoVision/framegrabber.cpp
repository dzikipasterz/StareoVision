#include "framegrabber.h"

frameGrabber::frameGrabber(QObject *parent) :
    QObject(parent),
    status(false)
{

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

}

void frameGrabber::receiveSetup(const int device)
{
    openDevice(device);
    if(!cap->isOpened()) {
        status = false;
        return;
    }

    status = true;
}
