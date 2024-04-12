#pragma once

#include <memory>
#include <string>

#include "../common/bytebuffer.h"

namespace rewiind {

namespace ast {

class ASTHeader
{
private:
    const unsigned int headerlen = 0x40;
    rewiind::common::ByteBuffer headerdata;

public:
    ASTHeader(rewiind::common::ByteBuffer& bytebuffer);

    const std::string getMagic();
    const uint32_t getFileSize();
    const uint16_t getAudioFormat();
    const uint16_t getBitDepth();
    const uint16_t getChannelCount();
    const uint32_t getSampleRate();
    const uint32_t getSampleCount();
    const uint32_t getLoopStart();
    const uint32_t getLoopEnd();
    const uint32_t getFirstBlockSize();
};

class BLCKHeader
{
private:
    //rewiind::common::ByteBuffer blockdata;

    const std::string getMagic();
    const uint32_t getBlockSize();
};

}

}