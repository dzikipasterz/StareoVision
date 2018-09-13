#include "stereobmcuda.h"

StereoBMcuda::StereoBMcuda()
{
    stereoBM = cv::cuda::createStereoBM();
    stereoBM->setBlockSize(19);
    //stereoBM->setPreFilterCap(61);
    //stereoBM->setSpeckleRange(20);
    stereoBM->setPreFilterCap(31);
    stereoBM->setSpeckleWindowSize(100);
    stereoBM->setUniquenessRatio(10);
    stereoBM->setSpeckleRange(32);
    stereoBM->setDisp12MaxDiff(1);
    filter = cv::cuda::createDisparityBilateralFilter(160, 11, 5);
    filter->setNumDisparities(160);
    filter->setEdgeThreshold(0.5);
    filter->setSigmaRange(2.0);
}


void StereoBMcuda::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    leftFrameGpu.upload(leftFrameRectified);
    rightFrameGpu.upload(rightFrameRectified);

    stereoBM->compute(leftFrameGpu, rightFrameGpu, dispGpu);
    filter->apply(dispGpu,leftFrameGpu, dispGpuOut);

    dispGpuOut.download(dispOut);
    dispOut.convertTo(dispOut, CV_8UC1);
}
