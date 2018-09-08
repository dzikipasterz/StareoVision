#ifndef VIDEOREADER_H
#define VIDEOREADER_H

#include <sourcereader.h>
#include <timerregulator.h>


class VideoReader : public SourceReader
{
    Q_OBJECT
public:
    VideoReader();
    ~VideoReader() override;

public slots:
    void receiveTimeout();

protected:
    void executeStart() override;
    void executePause() override;
    void executeResume() override;
    void executeJobDone() override;

private:
    timerRegulator *timer;
    cv::VideoCapture *leftCap, *rightCap;
    bool end;

    void startTimer();
    void grabFrames();
};

#endif // VIDEOREADER_H
