#include "stereosgbm.h"

StereoSGBM::StereoSGBM() :
    numOfDisparities(80),
    sgbmWinSize(5)
{
    leftMatcher = cv::StereoSGBM::create(0, numOfDisparities, sgbmWinSize);

    leftMatcher->setP1(24*sgbmWinSize*sgbmWinSize);
    leftMatcher->setP2(96*sgbmWinSize*sgbmWinSize);
    //leftMatcher->setMinDisparity(50);
    leftMatcher->setNumDisparities(numOfDisparities);
    leftMatcher->setPreFilterCap(63);
    //leftMatcher->setUniquenessRatio(10);
    //leftMatcher->setSpeckleWindowSize(100);
    //leftMatcher->setSpeckleRange(32);
    //leftMatcher->setDisp12MaxDiff(1);
    leftMatcher->setMode(cv::StereoSGBM::MODE_SGBM_3WAY);

    filter = cv::ximgproc::createDisparityWLSFilter(leftMatcher);
    filter->setLambda(8000.0);
    filter->setSigmaColor(1.5);
    rightMatcher = cv::ximgproc::createRightMatcher(leftMatcher);
}

void StereoSGBM::processFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{   
    leftMatcher->compute(leftFrame, rightFrame, leftDisp);
    rightMatcher->compute(rightFrame, leftFrame, rightDisp);
    filter->filter(leftDisp, leftFrame, filteredDisp, rightDisp);
    cv::ximgproc::getDisparityVis(filteredDisp, filteredDispVis);

    emit sendDisparityMap(filteredDispVis);
}
