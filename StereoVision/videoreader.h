#ifndef VIDEOREADER_H
#define VIDEOREADER_H

#include <sourcereader.h>
#include <timerregulator.h>


class VideoReader : public SourceReader
{
    Q_OBJECT
public:
    VideoReader(SourceReaderMode videoMode=stereo);
    ~VideoReader() override;

signals:
    void sendEnd();

public slots:
    void receiveTimeout();

protected:
    void executeStart() override;
    void executeStop() override;
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
