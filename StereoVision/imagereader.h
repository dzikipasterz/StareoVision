#ifndef IMAGEREADER_H
#define IMAGEREADER_H

#include <sourcereader.h>

class ImageReader : public SourceReader
{
public:
    ImageReader(SourceReaderMode mode=stereo);

protected:
    void executeStart() override;
    void executeJobDone() override;
};

#endif // IMAGEREADER_H
