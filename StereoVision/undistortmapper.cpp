#include "undistortmapper.h"

UndistortMapper::UndistortMapper(QObject *parent) : QObject(parent)
{
    readCalibFile();
}


void UndistortMapper::setCalibrationFile(QString filename)
{
    calibrationFile = filename;
}

void UndistortMapper::readCalibFile()
{
    cv::FileStorage file(calibrationFile.toUtf8().constData(), cv::FileStorage::READ);

    file["leftMap1"] >> leftMap1;
    file["leftMap2"] >> leftMap2;
    file["rightMap1"] >> rightMap1;
    file["rightMap2"] >> rightMap2;

    file.release();
}

void UndistortMapper::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    cv::Mat leftDst = leftFrame.clone();
    cv::Mat rightDst = rightFrame.clone();

    cv::remap(leftFrame, leftDst, leftMap1, leftMap2, cv::INTER_LINEAR);
    cv::remap(rightFrame, rightDst, rightMap1, rightMap2, cv::INTER_LINEAR);

    leftFrame.release();
    rightFrame.release();

    emit sendProcessedFrames(leftDst, rightDst);
}
