#include "imagereader.h"

ImageReader::ImageReader()
{

}


void ImageReader::receiveStart()
{
    cv::Mat leftGray, rightGray;
    cv::cvtColor((cv::imread(leftSourcePath.toUtf8().constData())), leftGray, CV_BGR2GRAY);
    cv::cvtColor((cv::imread(rightSourcePath.toUtf8().constData())), rightGray, CV_BGR2GRAY);
    emit sendFrames(leftGray, rightGray);
}
