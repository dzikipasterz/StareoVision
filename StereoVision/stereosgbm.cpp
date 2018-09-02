#include "stereosgbm.h"

StereoSGBM::StereoSGBM() :
    numOfDisparities(80),
    sgbmWinSize(1)
{
    leftMatcher = cv::StereoSGBM::create(20, numOfDisparities, sgbmWinSize);

    leftMatcher->setP1(24*sgbmWinSize*sgbmWinSize);
    leftMatcher->setP2(96*sgbmWinSize*sgbmWinSize);
    leftMatcher->setNumDisparities(numOfDisparities);
    leftMatcher->setPreFilterCap(63);
    leftMatcher->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);

    filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
    filter->setLambda(8000.0);
    filter->setSigmaColor(1.5);
    rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
}

void StereoSGBM::processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{   
    leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
    rightMatcher->compute(rightFrameRectified, leftFrameRectified, rightDisp);
    filter->filter(leftDisp, leftFrameRectified, filteredDisp, rightDisp);
    cv::ximgproc::getDisparityVis(filteredDisp, filteredDispVis);

    emit sendDisparity(leftFrameRaw, rightFrameRaw, filteredDispVis);
}
