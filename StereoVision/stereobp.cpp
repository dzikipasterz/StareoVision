#include "stereobp.h"

StereoBP::StereoBP()
{
    stereoBP = cv::cuda::createStereoBeliefPropagation();
}

StereoBP::~StereoBP()
{
   // delete stereoBP;
}


void StereoBP::processFrames(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat leftFrameRectified, cv::Mat rightFrameRectified)
{
    leftFrameGpu.upload(leftFrameRectified);
    rightFrameGpu.upload(rightFrameRectified);

    stereoBP->compute(leftFrameGpu, rightFrameGpu, dispGpu);

    dispGpu.download(dispOut);
    dispOut.convertTo(dispOut, CV_8UC1);

    emit sendDisparity(leftFrameRaw, rightFrameRaw, dispOut);
}
