#include "appsettings.h"

AppSettings::AppSettings() :
    leftCameraId(0),
    rightCameraId(1)
{

}

AppSettings::~AppSettings(){};

void AppSettings::setLeftCameraId(int cameraId)
{
    leftCameraId = cameraId;
}

int AppSettings::readLeftCameraId()
{
    return leftCameraId;
}

void AppSettings::setRightCameraId(int cameraId)
{
    rightCameraId = cameraId;
}

int AppSettings::readRightCameraId()
{
    return rightCameraId;
}
