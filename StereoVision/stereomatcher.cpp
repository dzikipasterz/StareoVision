#include "stereomatcher.h"

StereoMatcher::StereoMatcher(QObject *parent) : QObject(parent)
{

}

void StereoMatcher::process(cv::Mat, cv::Mat){}

void StereoMatcher::receiveFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    process(leftFrameRectified, rightFrameRectified);
    emit sendDisparityAndRaw(leftFrameRectified, rightFrameRectified, dispOut);
    emit sendDisparity(dispOut);
    emit sendJobDone();
}

