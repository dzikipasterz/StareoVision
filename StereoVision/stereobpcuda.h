#ifndef STEREOBP_H
#define STEREOBP_H

#include <stereomatcher.h>
#include <opencv2/cudastereo.hpp>

class StereoBPcuda : public StereoMatcher
{
public:
    StereoBPcuda();
    ~StereoBPcuda() override;

protected:
    void processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::cuda::StereoBeliefPropagation> stereoBPcuda;
    cv::Ptr<cv::cuda::DisparityBilateralFilter> filter;
    cv::cuda::GpuMat leftFrameGpu, rightFrameGpu, dispGpuOut;
    cv::Mat dispOut;
    int ndisp, iters, levels;
};

#endif // STEREOBP_H
