#pragma once

#include <memory>
#include <string>
#include <iterator>

#include "../common/header.h"

namespace rewiind {

namespace ast {

class ASTHeader : public common::GenericHeader
{
private:
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

    const std::string parseAudioFormat();

public:
    ASTHeader(common::ByteBuffer& bytebuffer);

    void printContents();
};

class BLCKHeader : public common::GenericHeader
{
private:
    const std::string getMagic();
    const uint32_t getBlockSize();
};

}

}