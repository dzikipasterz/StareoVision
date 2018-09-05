#ifndef BLOCKMATCHING_H
#define BLOCKMATCHING_H

#include <stereomatcher.h>

class StereoBMcpu : public StereoMatcher
{
public:
    StereoBMcpu();
    ~StereoBMcpu() override;

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

protected:
    void processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;
    void setup() override;

private:
    cv::Ptr<cv::StereoBM> leftMatcher;
    cv::Ptr<cv::StereoMatcher> rightMatcher;
    cv::Ptr<cv::ximgproc::DisparityWLSFilter> filter;
    cv::Mat leftDisp, rightDisp, filteredDisp, filteredDispVis;
    int numOfDisparities, winSize;
};

#endif // BLOCKMATCHING_H
