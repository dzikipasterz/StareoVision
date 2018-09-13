#include "videowriter.h"

VideoWriter::VideoWriter() :
    cap(nullptr),
    recordFlag(false)
{

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

    if(cap->isOpened()) emit sendFilePath(savePath);
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
        cap->write(frame);
    }
    else frameSize = frame.size();

    frame.release();
}


void VideoWriter::releaseWriter()
{
    if(cap != nullptr) cap->release();
}
