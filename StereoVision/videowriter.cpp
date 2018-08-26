#include "videowriter.h"

VideoWriter::VideoWriter(QString path) :
    leftCap(nullptr),
    rightCap(nullptr),
    recordFlag(false)
{
    savePath = path;
}

VideoWriter::~VideoWriter()
{
    releaseWriter();
}

void VideoWriter::receiveStartRecording()
{
    recordFlag = true;

    QDateTime currentTime = QDateTime::currentDateTime();
    QString L = ((currentTime.toString(Qt::ISODate)).append("_L.avi").prepend(savePath));
    QString R = ((currentTime.toString(Qt::ISODate)).append("_R.avi").prepend(savePath));

    leftCap = new cv::VideoWriter(L.toUtf8().constData(), CV_FOURCC('P','I','M','1'), 24, frameSize);
    rightCap = new cv::VideoWriter(R.toUtf8().constData(), CV_FOURCC('P','I','M','1'), 24, frameSize);
}

void VideoWriter::receiveStopRecording()
{
    recordFlag = false;
    releaseWriter();
}

void VideoWriter::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    if(recordFlag)
    {
        leftCap->write(leftFrame);
        rightCap->write(rightFrame);

    }
    else frameSize = leftFrame.size();

    leftFrame.release();
    rightFrame.release();
}


void VideoWriter::releaseWriter()
{
    if(leftCap != nullptr) leftCap->release();
    if(rightCap != nullptr) rightCap->release();
}
