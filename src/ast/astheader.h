#pragma once

#include <memory>
#include <string>
#include <iterator>

#include "../common/header.h"

namespace rewiind {

namespace ast {

class ASTHeader : public common::GenericBuffer
{
private:
    inline const std::string getMagic() { return this->bytes.BytestoString(0x00,4); }
    inline const uint32_t getFileSize() { return this->bytes.BytestoUint32(0x04); }
    inline const uint16_t getAudioFormat() { return this->bytes.BytestoUint16(0x08); }
    inline const uint16_t getBitDepth() { return this->bytes.BytestoUint16(0x0a); }
    inline const uint16_t getChannelCount() { return this->bytes.BytestoUint16(0x0c); }
    inline const uint32_t getSampleRate() { return this->bytes.BytestoUint32(0x10); }
    inline const uint32_t getSampleCount() { return this->bytes.BytestoUint32(0x14); }
    inline const uint32_t getLoopStart() { return this->bytes.BytestoUint32(0x18); }
    inline const uint32_t getLoopEnd() { return this->bytes.BytestoUint32(0x1c); }
    inline const uint32_t getFirstBlockSize() { return this->bytes.BytestoUint32(0x20); }

    const std::string parseAudioFormat();

public:
    ASTHeader(common::ByteBuffer& bytebuffer);
    ASTHeader(common::ByteBuffer&& bytebuffer);

    void printContents();
};

class BLCKHeader : public common::GenericBuffer
{
private:
    inline const std::string getMagic() { return this->bytes.BytestoString(0x00, 4); }
    inline const uint32_t getBlockSize() { return this->bytes.BytestoUint32(0x04); }
};

}

}