#ifndef STEREOBP_H
#define STEREOBP_H

#include <stereomatcher.h>
#include <opencv2/cudastereo.hpp>

class StereoBPcuda : public StereoMatcher
{
public:
    StereoBPcuda();

protected:
    void process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::cuda::StereoBeliefPropagation> stereoBP;
    cv::Ptr<cv::cuda::DisparityBilateralFilter> filter;
    cv::cuda::GpuMat leftFrameGpu, rightFrameGpu, dispGpuOut;
    int ndisp, iters, levels;
};

#endif // STEREOBP_H
