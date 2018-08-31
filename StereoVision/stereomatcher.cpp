#include "stereomatcher.h"

StereoMatcher::StereoMatcher(QObject *parent) : QObject(parent)
{
    readCalibFile();
}

void StereoMatcher::setCalibFile(QString file)
{
    calibrationFile = file;
}

void StereoMatcher::readCalibFile()
{
    cv::FileStorage file(calibrationFile.toUtf8().constData(), cv::FileStorage::READ);

    file["roi1"] >> roi1;
    file["roi2"] >> roi2;

    file.release();
}

void StereoMatcher::processFrames(cv::Mat, cv::Mat){}

void StereoMatcher::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    processFrames(leftFrame, rightFrame);
}

