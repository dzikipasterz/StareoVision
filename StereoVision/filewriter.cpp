#include "filewriter.h"

FileWriter::FileWriter(QObject *parent) : QObject(parent)
{

}


void FileWriter::receiveFrame(cv::Mat frame)
{
    executeReceiveFrame(frame);
}

void FileWriter::receiveStartWriting()
{
    executeReceiveStartWriting();
}

void FileWriter::receiveStopWriting()
{
    executeReceiveStopWriting();
}

void FileWriter::receiveSetSavePath(QString path)
{
    savePath = path;
}

void FileWriter::executeReceiveFrame(cv::Mat){};
void FileWriter::executeReceiveStartWriting(){};
void FileWriter::executeReceiveStopWriting(){};
