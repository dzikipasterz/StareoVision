#ifndef STEREOSGBM_H
#define STEREOSGBM_H

#include <QObject>
#include <stereomatcher.h>

class StereoSGBM : public StereoMatcher
{
public:
    StereoSGBM();

protected:
    void processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified) override;

private:
    cv::Ptr<cv::StereoSGBM> leftMatcher;
    cv::Ptr<cv::StereoMatcher> rightMatcher;
    cv::Ptr<cv::ximgproc::DisparityWLSFilter> filter;
    cv::Mat leftDisp, rightDisp, filteredDisp, filteredDispVis;
    int numOfDisparities;
    int sgbmWinSize;
};

#endif // STEREOSGBM_H
