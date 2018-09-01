#ifndef BLOCKMATCHING_H
#define BLOCKMATCHING_H

#include <stereomatcher.h>

class StereoBM : public StereoMatcher
{
public:
    StereoBM();
    ~StereoBM() override;

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

protected:
    void processFrames(cv::Mat leftFrame, cv::Mat rightFrame) override;
    void setup() override;

private:
    cv::Ptr<cv::StereoBM> bm;  
    cv::Mat disparityRaw, disparity;
    int numOfDisparities;
};

#endif // BLOCKMATCHING_H
