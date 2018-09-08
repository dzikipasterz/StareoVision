#ifndef BLOCKMATCHING_H
#define BLOCKMATCHING_H

#include <stereomatcher.h>

class StereoBMcpu : public StereoMatcher
{
public:
    StereoBMcpu();

protected:
    void process(cv::Mat lRect, cv::Mat rRect) override;

private:
    cv::Ptr<cv::StereoBM> leftMatcher;
    cv::Ptr<cv::StereoMatcher> rightMatcher;
    cv::Ptr<cv::ximgproc::DisparityWLSFilter> filter;
    cv::Mat leftDisp, rightDisp, filteredDisp;
    int numOfDisparities, winSize;
};

#endif // BLOCKMATCHING_H
