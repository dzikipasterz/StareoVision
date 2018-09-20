#include "stereocsbpcuda.h"

StereoCSBPcuda::StereoCSBPcuda(MatcherMode mode)
{
    matcherMode = mode;

    cv::cuda::StereoConstantSpaceBP::estimateRecommendedParams(1920, 1080, ndisp, iters, levels, nrPlane);
    stereoCSBP = cv::cuda::createStereoConstantSpaceBP(ndisp, iters, levels, nrPlane);

    if(matcherMode == MatcherMode::filter)
    {
        filter = cv::cuda::createDisparityBilateralFilter();
        filter->setNumDisparities(ndisp);
        filter->setEdgeThreshold(10.0);
        filter->setSigmaRange(1);
        filter->setRadius(11);
    }
}



void StereoCSBPcuda::process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    leftFrameGpu.upload(leftFrameRectified);
    rightFrameGpu.upload(rightFrameRectified);

    stereoCSBP->compute(leftFrameGpu, rightFrameGpu, dispGpuOut);
    if(matcherMode == MatcherMode::filter) filter->apply(dispGpuOut,leftFrameGpu, dispGpuOut);

    dispGpuOut.download(dispOut);
    dispOut.convertTo(dispOut, CV_8UC1);
}
