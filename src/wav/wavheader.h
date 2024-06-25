#pragma once

#include <string>

#include "../common/header.h"
#include "../common/bytebuffer.h"

namespace rewiind
{
    namespace wav
    {
        class RIFFHeader : public common::ByteBuffer, public common::GenericHeader
        {
        public:
            RIFFHeader(std::size_t hdr_size);
            RIFFHeader(const std::vector<char>& data);
            RIFFHeader(std::vector<char>&& data);

            inline const std::string getMagic() { return this->readString(0x00, 0x04); }
            inline const uint32_t getChunkSize() { return this->readUint32(0x04); }
            inline const std::string getFormat() { return this->readString(0x04, 0x08); }

            inline void setMagic(std::string data) { this->writeString(0x00, data); }
            inline void setChunkSize(uint32_t data) { this->writeUint32(0x04, data); }
            inline void setFormat(std::string data) { this->writeString(0x08, data); }

            void printContents();
        };

        class WAVHeader : public common::ByteBuffer, public common::GenericHeader
        {
        public:
            WAVHeader(std::size_t hdr_size);
            WAVHeader(const std::vector<char>& data);
            WAVHeader(std::vector<char>&& data);

            inline const std::string getMagic() { return this->readString(0x00, 0x04); }
            inline const uint32_t getChunkSize() { return this->readUint32(0x04); }
            inline const uint16_t getAudioFormat() { return this->readUint16(0x08); }
            inline const uint16_t getChannelCount() { return this->readUint16(0x0a); }
            inline const uint32_t getSampleRate() { return this->readUint32(0x0c); }
            inline const uint32_t getByteRate() { return this->readUint32(0x10); }
            inline const uint16_t getBlockAlign() { return this->readUint16(0x14); }
            inline const uint16_t getBitsSample() { return this->readUint16(0x16); }

            const std::string parseAudioFormat();

            inline void setMagic(std::string data) { this->writeString(0x00, data); }
            inline void setChunkSize(uint32_t data) { this->writeUint32(0x04, data); }
            inline void setAudioFormat(uint16_t data) { this->writeUint16(0x08, data); }
            inline void setChannelCount(uint16_t data) { this->writeUint16(0x0a, data); }
            inline void setSampleRate(uint32_t data) { this->writeUint32(0x0c, data); }
            inline void setByteRate(uint32_t data) { this->writeUint32(0x10, data); }
            inline void setBlockAlign(uint16_t data) { this->writeUint16(0x14, data); }
            inline void setBitsSample(uint16_t data) { this->writeUint16(0x16, data); }

            void printContents();
        };

        class WAVDataHdr : public common::ByteBuffer, public common::GenericHeader
        {
        public:
            WAVDataHdr(std::size_t hdr_size);
            WAVDataHdr(const std::vector<char>& data);
            WAVDataHdr(std::vector<char>&& data);

            inline const std::string getMagic() { return this->readString(0x00, 0x04); }
            inline const uint32_t getDataSize() { return this->readUint32(0x04); }
            
            inline void setMagic(std::string data) { this->writeString(0x00, data); }
            inline void setDataSize(uint32_t data) { this->writeUint32(0x04, data); }

            void printContents();
        };
    }
}