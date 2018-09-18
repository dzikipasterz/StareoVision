#include "videoreader.h"


VideoReader::VideoReader(SourceReaderMode videoMode) :
    sentFramesCounter(0),
    jobsDoneCounter(0),
    end(false),
    sizeSent(false)
{
    mode = videoMode;
}

VideoReader::~VideoReader()
{
    switch (mode)
    {
    case stereo:
        rightCap->release();
        //fall through

    case mono:
        leftCap->release();
    }

    timer->receivePause();
    delete timer;
}

void VideoReader::receiveTimeout()
{
    grabFrames();
}

void VideoReader::executeStart()
{
    switch(mode)
    {
    case stereo:
        rightCap = new cv::VideoCapture(rightSourcePath.toUtf8().constData());
        //fall through
    case mono:
        leftCap = new cv::VideoCapture(leftSourcePath.toUtf8().constData());
    }

    startTimer();
}


void VideoReader::executePause()
{
    timer->receivePause();
}

void VideoReader::executeStop()
{
    timer->receivePause();
}

void VideoReader::executeResume()
{
    timer->receiveResume();
}

void VideoReader::executeJobDone()
{
    timer->receiveJobDone();
    jobsDoneCounter++;
    checkEnd();
}

void VideoReader::startTimer()
{
    timer = new timerRegulator();
    connect(timer, SIGNAL(sendTimeout()), this, SLOT(receiveTimeout()));
    timer->setInterval(42);
    timer->receiveStart();
}

void VideoReader::checkEnd()
{
    if((jobsDoneCounter == sentFramesCounter) && end)
    {
        emit sendEnd();
    }
}

void VideoReader::grabFrames()
{
    cv::Mat leftFrame, rightFrame, leftGray, rightGray;

    switch (mode)
    {
    case stereo:
        (*leftCap) >> leftFrame;
        (*rightCap) >> rightFrame;

        if(leftFrame.empty() || rightFrame.empty())
        {
            end = true;
            timer->receivePause();
            checkEnd();
        }
        else
        {
            cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
            cv::cvtColor(rightFrame, rightGray, CV_BGR2GRAY);
            if(!sizeSent)
            {
                emit sendFrameSize(cv::Size(leftGray.size()));
                sizeSent = true;
            }
            emit sendFrames(leftGray, rightGray);
            sentFramesCounter++;
        }

        break;
    case mono:
        (*leftCap) >> leftFrame;

        if(leftFrame.empty())
        {
            end = true;
            timer->receivePause();
            checkEnd();
        }
        else
        {
            cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
            if(!sizeSent)
            {
                emit sendFrameSize(cv::Size(leftGray.size()));
                sizeSent = true;
            }
            emit sendFrame(leftGray);
            sentFramesCounter++;
        }
        break;
    }
}
