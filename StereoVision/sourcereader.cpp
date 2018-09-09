#include "sourcereader.h"

SourceReader::SourceReader(QObject *parent) : QObject(parent)
{

}

void SourceReader::setSourcePaths(QString leftPath, QString rightPath)
{
    leftSourcePath = leftPath;
    rightSourcePath = rightPath;
}

void SourceReader::executeStart(){}
void SourceReader::executeStop(){}
void SourceReader::executePause(){}
void SourceReader::executeResume(){}
void SourceReader::executeJobDone(){}

void SourceReader::receiveStart()
{
    executeStart();
}

void SourceReader::receiveStop()
{
    executeStop();
}

void SourceReader::receivePause()
{
    executePause();
}

void SourceReader::receiveResume()
{
    executeResume();
}

void SourceReader::receiveJobDone()
{
    executeJobDone();
}
