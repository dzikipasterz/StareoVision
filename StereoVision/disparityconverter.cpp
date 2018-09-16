#include "disparityconverter.h"

DisparityConverter::DisparityConverter(QObject *parent) : QObject(parent)
{

}

void DisparityConverter::receiveDisparity(cv::Mat leftFrameRaw, cv::Mat rightFrameRaw, cv::Mat disparityFrame)
{
    emit sendDisparityAndRaw(leftFrameRaw, rightFrameRaw, disparityFrame);
}
