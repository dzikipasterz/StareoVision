#ifndef STEREOCSBPCUDA_H
#define STEREOCSBPCUDA_H

#include <stereomatcher.h>
#include <opencv2/cudastereo.hpp>

class StereoCSBPcuda : public StereoMatcher
{
public:
    StereoCSBPcuda();

protected:
    void process(cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::cuda::StereoConstantSpaceBP> stereoCSBP;
    cv::Ptr<cv::cuda::DisparityBilateralFilter> filter;
    cv::cuda::GpuMat leftFrameGpu, rightFrameGpu, dispGpu, dispGpuOut;
    int ndisp, iters, levels, nrPlane;
};

#endif // STEREOCSBPCUDA_H
