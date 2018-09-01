#include "stereobm.h"

StereoBM::StereoBM() :
    numOfDisparities(16)
{

}

StereoBM::~StereoBM()
{
}

void StereoBM::setup()
{
    bm = cv::StereoBM::create(numOfDisparities, 9);
/*
    bm->setROI1(roi1);
    bm->setROI2(roi2);
    bm->setPreFilterCap(31);
    bm->setMinDisparity(0);
    bm->setTextureThreshold(10);
    bm->setUniquenessRatio(15);
    bm->setSpeckleWindowSize(100);
    bm->setSpeckleRange(32);
    bm->setDisp12MaxDiff(1);
*/
}


void StereoBM::processFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    bm->compute(leftFrame, rightFrame, disparityRaw);
    disparityRaw.convertTo(disparity, CV_8U, 255/(numOfDisparities*16.));

    emit sendDisparityMap(disparity);
    //emit sendDisparityMap(leftFrame);
}
