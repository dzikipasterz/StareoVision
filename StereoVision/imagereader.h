#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <sourcereader.h>

class ImageReader : public SourceReader
{
public:
    ImageReader();

public slots:
    void receiveStart() override;
};

#endif // IMAGEREADER_H
