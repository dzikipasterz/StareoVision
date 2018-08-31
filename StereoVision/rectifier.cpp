#include "rectifier.h"

Rectifier::Rectifier(QObject *parent) : QObject(parent)
{

}


void Rectifier::setCalibrationFile(QString filename)
{
    calibrationFile = filename;
    readCalibFile();
}

void Rectifier::readCalibFile()
{
    cv::FileStorage file(calibrationFile.toUtf8().constData(), cv::FileStorage::READ);

    file["leftMap1"] >> leftMap1;
    file["leftMap2"] >> leftMap2;
    file["rightMap1"] >> rightMap1;
    file["rightMap2"] >> rightMap2;

    file.release();
}

void Rectifier::receiveFrames(cv::Mat leftFrame, cv::Mat rightFrame)
{
    cv::Mat leftDst = leftFrame.clone();
    cv::Mat rightDst = rightFrame.clone();

    cv::remap(leftFrame, leftDst, leftMap1, leftMap2, cv::INTER_LINEAR);
    cv::remap(rightFrame, rightDst, rightMap1, rightMap2, cv::INTER_LINEAR);

    leftFrame.release();
    rightFrame.release();

    emit sendFrames(leftDst, rightDst);
}
