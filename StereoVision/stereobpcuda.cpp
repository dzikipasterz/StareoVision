#include "stereobpcuda.h"

StereoBPcuda::StereoBPcuda()
{
    cv::cuda::StereoBeliefPropagation::estimateRecommendedParams(640, 480, ndisp, iters, levels);
    stereoBPcuda = cv::cuda::createStereoBeliefPropagation(ndisp, iters, levels);
    filter = cv::cuda::createDisparityBilateralFilter();
    filter->setNumDisparities(ndisp);
    filter->setEdgeThreshold(10.0);
    filter->setSigmaRange(0.25);
    filter->setRadius(11);
}

StereoBPcuda::~StereoBPcuda()
{
   // delete stereoBP;
}


void StereoBPcuda::processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    leftFrameGpu.upload(leftFrameRectified);
    rightFrameGpu.upload(rightFrameRectified);

    stereoBPcuda->compute(leftFrameGpu, rightFrameGpu, dispGpu);
    filter->apply(dispGpu,leftFrameGpu, dispGpuOut);

    dispGpuOut.download(dispOut);
    dispOut.convertTo(dispOut, CV_8UC1);

    emit sendDisparity(leftFrameRaw, rightFrameRaw, dispOut);
}
