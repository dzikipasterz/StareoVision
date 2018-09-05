#include "rectifier.h"

Rectifier::Rectifier(QObject *parent) : QObject(parent)
{
    //clahe = cv::createCLAHE(40.0, cv::Size(8,8));
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
    if(leftFrame.type() != CV_8UC1)
    {
        cv::cvtColor(leftFrame, leftFrame, CV_BGR2GRAY);
    }

    if(rightFrame.type() != CV_8UC1)
    {
        cv::cvtColor(rightFrame, rightFrame, CV_BGR2GRAY);
    }

    cv::equalizeHist(leftFrame, leftFrame);
    cv::equalizeHist(rightFrame, rightFrame);\

    cv::fastNlMeansDenoising(leftFrame, leftFrame);
    cv::fastNlMeansDenoising(rightFrame, rightFrame);

    cv::Mat leftDst = leftFrame.clone();
    cv::Mat rightDst = rightFrame.clone();

    cv::remap(leftFrame, leftDst, leftMap1, leftMap2, cv::INTER_LINEAR);
    cv::remap(rightFrame, rightDst, rightMap1, rightMap2, cv::INTER_LINEAR);
    //clahe->apply(leftDst,leftDst);
    //clahe->apply(rightDst, rightDst);


    emit sendFrames(leftFrame, rightFrame, leftDst, rightDst);
}
