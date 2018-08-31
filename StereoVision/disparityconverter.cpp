#include "disparityconverter.h"

DisparityConverter::DisparityConverter(QObject *parent) : QObject(parent)
{

}

void DisparityConverter::receiveFrame(cv::Mat disparityFrame)
{
    emit sendFrame(disparityFrame);
}
