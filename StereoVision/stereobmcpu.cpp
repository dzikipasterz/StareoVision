#include "stereobmcpu.h"

StereoBMcpu::StereoBMcpu(MatcherMode mode) :
    numOfDisparities(160),
    winSize(25)
{
    matcherMode = mode;

    if(matcherMode == MatcherMode::pure)
    {
        leftMatcher = cv::StereoBM::create(numOfDisparities, winSize);
    }
    else if(matcherMode == MatcherMode::filter)
    {
        leftMatcher = cv::StereoBM::create(numOfDisparities, winSize);
        filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
        filter->setLambda(24000.0);
        filter->setSigmaColor(0.8);
        rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
    }
}


void StereoBMcpu::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    if(matcherMode == MatcherMode::pure)
    {
        leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
        leftDisp.convertTo(dispOut, CV_8U, 255/(numOfDisparities*16.));
    }

    else if(matcherMode == MatcherMode::filter)
    {
        leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
        rightMatcher->compute(rightFrameRectified, leftFrameRectified, rightDisp);
        filter->filter(leftDisp, leftFrameRectified, filteredDisp, rightDisp);
        cv::ximgproc::getDisparityVis(filteredDisp, dispOut);
    }
}
