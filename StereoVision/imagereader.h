#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <sourcereader.h>

class ImageReader : public SourceReader
{
public:
    ImageReader();

protected:
    void executeStart() override;
};

#endif // IMAGEREADER_H
