#include "stereosgbmcpu.h"

StereoSGBMcpu::StereoSGBMcpu() :
    numOfDisparities(160),
    winSize(13)
{
    leftMatcher = cv::StereoSGBM::create(1, numOfDisparities, winSize);

    leftMatcher->setP1(4*winSize*winSize);
    leftMatcher->setP2(24*winSize*winSize);
    leftMatcher->setNumDisparities(numOfDisparities);
    leftMatcher->setPreFilterCap(31);
    leftMatcher->setMode(cv::StereoSGBM::MODE_HH4);
    leftMatcher->setSpeckleWindowSize(100);
    leftMatcher->setUniquenessRatio(10);
    leftMatcher->setSpeckleRange(32);
    leftMatcher->setDisp12MaxDiff(1);


    filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
    filter->setLambda(24000.0);
    filter->setSigmaColor(1.0);
    rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
}

void StereoSGBMcpu::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{   
    leftMatcher->compute(leftFrameRectified, rightFrameRectified, leftDisp);
    //leftDisp.convertTo(filteredDispVis, CV_8U, 255/(numOfDisparities*16.));
    rightMatcher->compute(rightFrameRectified, leftFrameRectified, rightDisp);
    filter->filter(leftDisp, leftFrameRectified, filteredDisp, rightDisp);
    cv::ximgproc::getDisparityVis(filteredDisp, dispOut);
}
