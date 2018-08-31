#include "blockmatching.h"

BlockMatching::BlockMatching()
{
    bm = cv::StereoBM::create(160, 10);

    bm->setROI1(roi1);
    bm->setROI2(roi2);
    bm->setPreFilterCap(31);
    bm->setMinDisparity(0);
    bm->setTextureThreshold(10);
    bm->setUniquenessRatio(15);
    bm->setSpeckleWindowSize(100);
    bm->setSpeckleRange(32);
    bm->setDisp12MaxDiff(1);
}

BlockMatching::~BlockMatching()
{
    delete bm;
}


void BlockMatching::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    bm->compute(leftFrame, rightFrame, disparity);
    emit sendDisparityMap(disparity);
}
