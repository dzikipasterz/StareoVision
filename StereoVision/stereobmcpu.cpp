#include "stereobmcpu.h"

StereoBMcpu::StereoBMcpu() :
    numOfDisparities(160),
    winSize(13)
{
    leftMatcher = cv::StereoBM::create(numOfDisparities, winSize);
    filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
    filter->setLambda(10000.0);
    filter->setSigmaColor(1.0);
    rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
}


void StereoBMcpu::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
    rightMatcher->compute(rightFrameRectified, leftFrameRectified, rightDisp);
    filter->filter(leftDisp, leftFrameRectified, filteredDisp, rightDisp);
    cv::ximgproc::getDisparityVis(filteredDisp, dispOut);
}
