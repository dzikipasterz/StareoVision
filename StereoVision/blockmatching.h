#ifndef BLOCKMATCHING_H
#define BLOCKMATCHING_H

#include <stereomatcher.h>

class BlockMatching : public StereoMatcher
{
public:
    BlockMatching();
    ~BlockMatching() override;

public slots:
    void receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame);

private:
    cv::StereoBM *bm;
    cv::Mat disparity;
};

#endif // BLOCKMATCHING_H
