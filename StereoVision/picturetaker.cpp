#include "picturetaker.h"

PictureTaker::PictureTaker(QObject *parent) :
    QObject(parent),
    takePictureFlag(false),
    savePath("/home/slawko/StereoVisionCalibrationImages/")
{

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
        //QString path = savePath.append("LeftImage");
        cv::imwrite("/home/slawko/StereoVisionCalibrationImages/LeftImage.jpg", leftFrame);
        //path = savePath.append("RightImage");
        cv::imwrite("/home/slawko/StereoVisionCalibrationImages/RightImage.jpg", rightFrame);
    }
}
