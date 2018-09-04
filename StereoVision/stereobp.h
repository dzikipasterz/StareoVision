#ifndef STEREOBP_H
#define STEREOBP_H

#include <stereomatcher.h>
#include <opencv2/cudastereo.hpp>

class StereoBP : public StereoMatcher
{
public:
    StereoBP();
    ~StereoBP() override;

protected:
    void processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::cuda::StereoBeliefPropagation> stereoBP;
    cv::cuda::GpuMat leftFrameGpu, rightFrameGpu, dispGpu;
    cv::Mat dispOut;

};

#endif // STEREOBP_H
