#include "stereosgbmcpu.h"

StereoSGBMcpu::StereoSGBMcpu(MatcherMode mode) :
    numOfDisparities(160),
    winSize(13)
{
    matcherMode = mode;

    leftMatcher = cv::StereoSGBM::create(1, numOfDisparities, winSize);
    leftMatcher->setP1(8*winSize*winSize);
    leftMatcher->setP2(32*winSize*winSize);
    leftMatcher->setNumDisparities(numOfDisparities);
    leftMatcher->setMinDisparity(1);
    leftMatcher->setPreFilterCap(31);
    leftMatcher->setMode(cv::StereoSGBM::MODE_HH4);
    leftMatcher->setSpeckleWindowSize(200);
    //leftMatcher->setUniquenessRatio(10);
    leftMatcher->setSpeckleRange(1);
    //leftMatcher->setDisp12MaxDiff(1);


    if(matcherMode == MatcherMode::filter)
    {
        filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
        filter->setLambda(8000);
        filter->setSigmaColor(0.8);
        rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
    }

}

void StereoSGBMcpu::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{   

    if(matcherMode == MatcherMode::pure)
    {
        leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
        leftDisp.convertTo(dispOut, CV_8U, 255/(numOfDisparities*16.));
    }

    else if(matcherMode == MatcherMode::filter)
    {
        rightMatcher->compute(rightFrameRectified, leftFrameRectified, rightDisp);
        filter->filter(leftDisp, leftFrameRectified, filteredDisp, rightDisp);
        cv::ximgproc::getDisparityVis(filteredDisp, dispOut);
    }
}
