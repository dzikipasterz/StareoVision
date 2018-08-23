#include "appsettings.h"

AppSettings::AppSettings() :
    leftCameraId(0),
    rightCameraId(1),
    calibPictsSavePath("/home/")
{
    readConfigFile();
}

AppSettings::~AppSettings()
{
    writeConfigFile();
}

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

void AppSettings::setCalibPictsSavePath(QString path)
{
    calibPictsSavePath = path;
}

QString AppSettings::readCalibPictSavePath()
{
    return calibPictsSavePath;
}

void AppSettings::setCalibFilesDir(QString path)
{
    calibFilesDir = path;
}

QString AppSettings::readCalibFilesDir()
{
    return calibFilesDir;
}

void AppSettings::setCalibFilePath(QString path)
{
    calibFilePath = path;
}

QString AppSettings::readCalibFilePath()
{
    return calibFilePath;
}

void AppSettings::setMovFilesDir(QString path)
{
    movFilesDir = path;
}

QString AppSettings::readMovFilesDir()
{
    return movFilesDir;
}

void AppSettings::readConfigFile()
{
    leftCameraId = 1;
    rightCameraId = 2;
    calibPictsSavePath = "/home/slawko/StereoVisionDir/Pictures/";
    calibFilesDir = "/home/slawko/StereoVisionDir/Calibration Files/";
    calibFilePath = "/home/slawko/StereoVisionDir/Calibration Files/kalibracja.calib";
    movFilesDir = "/home/slawko/StereoVisionDir/Movies/";
}

void AppSettings::writeConfigFile()
{

}
