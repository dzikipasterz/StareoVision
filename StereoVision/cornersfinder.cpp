#include "cornersfinder.h"

CornersFinder::CornersFinder(QObject *parent) :
    QObject(parent)
{

}

void CornersFinder::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    emit sendProcessedFrames(leftFrame, rightFrame);
    emit sendJobDone();
}
