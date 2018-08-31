#include "postfilter.h"

PostFilter::PostFilter(QObject *parent) : QObject(parent)
{

}

void PostFilter::processFrame(cv::Mat){}

void PostFilter::receiveFrame(cv::Mat frame)
{
    //processFrame(frame);
    emit sendFrame(frame); // #todo: chwilowe rozwiazanie
}
