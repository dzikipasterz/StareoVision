#include "blockmatching.h"

BlockMatching::BlockMatching()
{
    bm = cv::StereoBM::create(160, 10);
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
