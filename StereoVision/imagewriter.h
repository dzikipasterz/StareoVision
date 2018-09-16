#ifndef IMAGEWRITER_H
#define IMAGEWRITER_H

#include <QObject>
#include <filewriter.h>

class ImageWriter : public FileWriter
{
public:
    ImageWriter();

protected:
    void executeReceiveFrame(cv::Mat frame) override;
};

#endif // IMAGEWRITER_H
