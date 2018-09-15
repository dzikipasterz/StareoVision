#include "videoreader.h"


VideoReader::VideoReader(videoReaderMode videoMode) :
    end(false)
{
    mode = videoMode;
}

VideoReader::~VideoReader()
{
    switch (mode)
    {
    case stereo:
        delete leftCap;
        delete rightCap;
        break;

    case mono:
        delete leftCap;
        break;

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
}

void VideoReader::startTimer()
{
    timer = new timerRegulator();
    connect(timer, SIGNAL(sendTimeout()), this, SLOT(receiveTimeout()));
    timer->setInterval(42);
    timer->receiveStart();
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
            emit sendEnd();
        }
        else
        {
            cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
            cv::cvtColor(rightFrame, rightGray, CV_BGR2GRAY);
            emit sendFrames(leftGray, rightGray);
        }

        break;
    case mono:
        (*leftCap) >> leftFrame;

        if(leftFrame.empty())
        {
            end = true;
            timer->receivePause();
            emit sendEnd();
        }
        else
        {
            cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
            emit sendFrames(leftGray, rightGray);
        }
        break;
    }
}
