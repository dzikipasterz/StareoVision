#include "imagewriter.h"

ImageWriter::ImageWriter()
{

}

void ImageWriter::executeReceiveFrame(cv::Mat frame)
{
    cv::imwrite(savePath.toUtf8().constData(), frame);
}
