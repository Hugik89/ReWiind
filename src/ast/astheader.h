#pragma once

#include <memory>
#include <string>
#include <iterator>

#include "../common/header.h"
#include "../common/bytebuffer.h"

namespace rewiind 
{
    namespace ast 
    {
        class ASTHeader : public common::ByteBuffer, common::GenericHeader
        {
        public:
            ASTHeader(const std::vector<char>& data);
            ASTHeader(std::vector<char>&& data);

            inline const std::string getMagic() { return this->readString(0x00, 0x04); }
            inline const uint32_t getFileSize() { return this->readUint32(0x04); }
            inline const uint16_t getAudioFormat() { return this->readUint16(0x08); }
            inline const uint16_t getBitDepth() { return this->readUint16(0x0a); }
            inline const uint16_t getChannelCount() { return this->readUint16(0x0c); }
            inline const uint32_t getSampleRate() { return this->readUint32(0x10); }
            inline const uint32_t getSampleCount() { return this->readUint32(0x14); }
            inline const uint32_t getLoopStart() { return this->readUint32(0x18); }
            inline const uint32_t getLoopEnd() { return this->readUint32(0x1c); }
            inline const uint32_t getFirstBlockSize() { return this->readUint32(0x20); }

            const std::string parseAudioFormat();

            inline void setMagic(std::string data) { this->writeString(0x00, data); }
            inline void setFileSize(uint32_t data) { this->writeUint32(0x04, data); }
            inline void setAudioFormat(uint16_t data) { this->writeUint16(0x08, data); }
            inline void setBitDepth(uint16_t data) { this->writeUint16(0x0a, data); }
            inline void setChannelCount(uint16_t data) { this->writeUint16(0x0c, data); }
            inline void setSampleRate(uint32_t data) { this->writeUint32(0x10, data); }
            inline void setSampleCount(uint32_t data) { this->writeUint32(0x14, data); }
            inline void setLoopStart(uint32_t data) { this->writeUint32(0x18, data); }
            inline void setLoopEnd(uint32_t data) { this->writeUint32(0x1c, data); }
            inline void setFirstBlockSize(uint32_t data) { this->writeUint32(0x20, data); }

            void printContents();
        };
    }
}