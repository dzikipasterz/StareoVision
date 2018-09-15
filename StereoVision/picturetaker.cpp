#include "picturetaker.h"

PictureTaker::PictureTaker() :
    takePictureFlag(false)
{

}

void PictureTaker::receiveTakePicture()
{
    takePictureFlag=true;
}

void PictureTaker::receiveFrame(cv::Mat frame)
{
    if(takePictureFlag)
    {     
        takePictureFlag=false;
        cv::imwrite(savePath.toUtf8().constData(), frame);

        emit sendImagePath(savePath);
    }
}

void PictureTaker::receiveSetPath(QString path)
{
    savePath = path;
}

