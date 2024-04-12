#include "astheader.h"

using namespace rewiind::ast;

ASTHeader::ASTHeader(common::ByteBuffer& bytebuffer)
{
    this->bytes = std::move(bytebuffer);
}

ASTHeader::ASTHeader(common::ByteBuffer&& bytebuffer)
{
    this->bytes = std::move(bytebuffer);
}

inline
const std::string ASTHeader::getMagic()
{
    return this->bytes.BytestoString(0x00,4);
}

inline
const uint32_t ASTHeader::getFileSize()
{
    return this->bytes.BytestoUint32(0x04);
}

inline
const uint16_t ASTHeader::getAudioFormat()
{
    return this->bytes.BytestoUint16(0x08);
}

inline
const uint16_t ASTHeader::getBitDepth()
{
    return this->bytes.BytestoUint16(0x0a);
}

inline
const uint16_t ASTHeader::getChannelCount()
{
    return this->bytes.BytestoUint16(0x0c);
}

inline
const uint32_t ASTHeader::getSampleRate()
{
    return this->bytes.BytestoUint32(0x10);
}

inline
const uint32_t ASTHeader::getSampleCount()
{
    return this->bytes.BytestoUint32(0x14);
}

inline
const uint32_t ASTHeader::getLoopStart()
{
    return this->bytes.BytestoUint32(0x18);
}

inline
const uint32_t ASTHeader::getLoopEnd()
{
    return this->bytes.BytestoUint32(0x1c);
}

inline
const uint32_t ASTHeader::getFirstBlockSize()
{
    return this->bytes.BytestoUint32(0x20);
}

const std::string ASTHeader::parseAudioFormat()
{
    const uint16_t fmt = this->getAudioFormat();
    switch (fmt)
    {
    case 0:
        return "ADPCM";
    
    case 1:
        return "PCM16";
    
    default:
        return "Unknown";
    }
}

void ASTHeader::printContents()
{
    std::cout << "# AST header contents" << std::endl;
    std::cout << "Magic number : " << this->getMagic() << std::endl;
    std::cout << "File size (bytes): " << this->getFileSize() << std::endl;
    std::cout << "Audio format : " << this->parseAudioFormat() << std::endl;
    std::cout << "Bit depth : " << this->getBitDepth() << std::endl;
    std::cout << "Number of channels : " << this->getChannelCount() << std::endl;
    std::cout << "Sample rate (Hz) : " << this->getSampleRate() << std::endl;
    std::cout << "Total number of samples : " << this->getSampleCount() << std::endl;
    std::cout << "Loop start (sample count) : " << this->getLoopStart() << std::endl;
    std::cout << "Loop end (sample count) : " << this->getLoopEnd() << std::endl;
    std::cout << "First block size (bytes) : " << this->getFirstBlockSize() << std::endl;
}