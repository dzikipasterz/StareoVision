#include "imagereader.h"

ImageReader::ImageReader(SourceReaderMode imageMode)
{
    mode = imageMode;
}


void ImageReader::executeStart()
{
    cv::Mat leftFrame, leftGray, rightFrame, rightGray;

    switch (mode)
    {
    case stereo:
        rightFrame = cv::imread(rightSourcePath.toUtf8().constData());
        cv::cvtColor(rightFrame, rightGray, CV_BGR2GRAY);
    case mono:
        leftFrame = cv::imread(leftSourcePath.toUtf8().constData());
        cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
    }

    switch (mode)
    {
    case stereo:
        emit sendFrames(leftGray, rightGray);
        break;
    case mono:
        emit sendFrame(leftGray);
        break;
    }


}
