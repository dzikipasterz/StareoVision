#include "videoreader.h"

VideoReader::VideoReader() :
    end(false)
{

}

VideoReader::~VideoReader()
{
    delete leftCap;
    delete rightCap;
    timer->receivePause();
    delete timer;
}

void VideoReader::receiveTimeout()
{
    grabFrame();
}

void VideoReader::executeStart()
{
    leftCap = new cv::VideoCapture(leftSourcePath.toUtf8().constData());
    rightCap = new cv::VideoCapture(rightSourcePath.toUtf8().constData());
    startTimer();
}


void VideoReader::executePause()
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
    (*leftCap) >> leftFrame;
    (*rightCap) >> rightFrame;

    if(leftFrame.empty() || rightFrame.empty())
    {
        end = true;
        timer->receivePause();
    }
    else
    {
        cv::cvtColor(leftFrame, leftGray, CV_BGR2GRAY);
        cv::cvtColor(rightFrame, rightGray, CV_BGR2GRAY);
        emit sendFrames(leftGray, rightGray);
    }
}
