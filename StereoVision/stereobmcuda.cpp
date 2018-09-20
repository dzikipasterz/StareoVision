#include "stereobmcuda.h"

StereoBMcuda::StereoBMcuda(MatcherMode mode)
{
    matcherMode = mode;

    switch (matcherMode)
    {
    case MatcherMode::filter:
        filter = cv::cuda::createDisparityBilateralFilter(160, 11, 5);
        filter->setNumDisparities(160);
        filter->setEdgeThreshold(10.0);
        filter->setSigmaRange(0.8);
        //fall through
    case MatcherMode::pure:
        stereoBM = cv::cuda::createStereoBM();
        stereoBM->setBlockSize(23);
        stereoBM->setNumDisparities(160);
        //stereoBM->setPreFilterCap(61);
        //stereoBM->setSpeckleRange(20);
        //stereoBM->setPreFilterCap(31);
        //stereoBM->setSpeckleWindowSize(100);
        //stereoBM->setUniquenessRatio(10);
        //stereoBM->setSpeckleRange(32);
        //stereoBM->setDisp12MaxDiff(1);
    }
}


void StereoBMcuda::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{


    leftFrameGpu.upload(leftFrameRectified);
    rightFrameGpu.upload(rightFrameRectified);

    stereoBM->compute(leftFrameGpu, rightFrameGpu, dispGpuOut);

    if(matcherMode == MatcherMode::filter)
    {
      filter->apply(dispGpuOut,leftFrameGpu, dispGpuOut);
    }

    dispGpuOut.download(dispOut);
    dispOut.convertTo(dispOut, CV_8UC1);
}
