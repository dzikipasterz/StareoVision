#include "videowriter.h"

VideoWriter::VideoWriter() :
    cap(nullptr),
    recordFlag(false)
{
    connect(this, SIGNAL(sendOpenRetry()), this, SLOT(receiveOpenRetry()), Qt::QueuedConnection);
}

VideoWriter::~VideoWriter()
{
    releaseWriter();
}

void VideoWriter::executeReceiveStartWriting()
{
    recordFlag = true;

    cap = new cv::VideoWriter();

    cap->open(savePath.toUtf8().constData(), CV_FOURCC( 'D','I','V','X'), 24.0, frameSize, true);
    bool test = cap->isOpened();

    if(test) emit sendFilePath(savePath);
    else emit sendOpenRetry();
}

void VideoWriter::executeReceiveStopWriting()
{
    recordFlag = false;
    releaseWriter();
}

void VideoWriter::executeReceiveFrame(cv::Mat frame)
{
    if(recordFlag && cap->isOpened())
    {
        if(frame.channels() == 1)
        {
            cv::Mat imgArr[] {frame, frame, frame};
            cv::merge(imgArr, 3, frame);
        }

        cap->write(frame);
    }
    else frameSize = frame.size();

    frame.release();
}

void VideoWriter::executeReceiveFrameSize(cv::Size size)
{
    frameSize = size;
}


void VideoWriter::receiveOpenRetry()
{
    executeReceiveStartWriting();
}

void VideoWriter::releaseWriter()
{
    if(cap != nullptr)
        while(cap->isOpened())cap->release();
}
