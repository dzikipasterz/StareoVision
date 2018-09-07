#include "picturetaker.h"

PictureTaker::PictureTaker(QString path) :
    takePictureFlag(false)
{
    savePath = path;
}

void PictureTaker::receiveTakePicture()
{
    takePictureFlag=true;
}

void PictureTaker::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    if(takePictureFlag)
    {     
        takePictureFlag=false;
        QDateTime currentTime = QDateTime::currentDateTime();
        QString L = ((currentTime.toString(Qt::ISODate)).append("_L.jpg").prepend(savePath));
        QString R = ((currentTime.toString(Qt::ISODate)).append("_R.jpg").prepend(savePath));
        cv::imwrite(L.toUtf8().constData(), leftFrame);
        cv::imwrite(R.toUtf8().constData(), rightFrame);

        emit sendImagesPaths(L, R);
    }
}
