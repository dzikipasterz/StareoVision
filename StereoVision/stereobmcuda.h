#ifndef STEREOBMCUDA_H
#define STEREOBMCUDA_H

#include <stereomatcher.h>
#include <opencv2/cudastereo.hpp>

class StereoBMcuda : public StereoMatcher
{
public:
    StereoBMcuda();

protected:
    void processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::cuda::StereoBM> stereoBM;
    cv::Ptr<cv::cuda::DisparityBilateralFilter> filter;
    cv::cuda::GpuMat leftFrameGpu, rightFrameGpu, dispGpu, dispGpuOut;
    cv::Mat dispOut;
};

#endif // STEREOBMCUDA_H
