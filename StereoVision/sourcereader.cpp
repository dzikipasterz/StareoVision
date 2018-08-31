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

void SourceReader::receiveStart()
{
    executeStart();
}
