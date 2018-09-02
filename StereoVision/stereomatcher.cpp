#include "stereomatcher.h"

StereoMatcher::StereoMatcher(QObject *parent) : QObject(parent)
{

}

void StereoMatcher::setCalibFile(QString file)
{
    calibrationFile = file;
    readCalibFile();
    setup();
}

void StereoMatcher::readCalibFile()
{
    cv::FileStorage file(calibrationFile.toUtf8().constData(), cv::FileStorage::READ);

    file["roi1"] >> roi1;
    file["roi2"] >> roi2;

    file.release();
}

void StereoMatcher::processFrames(cv::Mat, cv::Mat, cv::Mat, cv::Mat){}
void StereoMatcher::setup(){};

void StereoMatcher::receiveFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    processFrames(leftFrameRaw, rightFrameRaw, leftFrameRectified, rightFrameRectified);
    emit sendJobDone();
}

