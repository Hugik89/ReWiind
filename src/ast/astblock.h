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
        class BLCKHeader : public common::ByteBuffer, public common::GenericHeader
        {   
        public:
            BLCKHeader(std::size_t buf_len);
            BLCKHeader(const std::vector<char>& data);
            BLCKHeader(std::vector<char>&& data);

            inline const std::string getMagic() { return this->readString(0x00, 0x04); }
            inline const uint32_t getBlockSize() { return this->readUint32(0x04); }

            inline void setMagic(std::string data) { this->writeString(0x00, data); }
            inline void setBlockSize(uint32_t data) { this->writeUint32BE(0x04, data); }

            void printContents();
        };

        class ASTBlock : public common::ByteBuffer
        {
        private:
            uint32_t bytes_per_sample_;
            std::size_t offset = 0;

        public:
            ASTBlock(uint16_t bit_depth, std::size_t buf_len);
            ASTBlock(uint16_t bit_depth, const std::vector<char>& data);
            ASTBlock(uint16_t bit_depth, std::vector<char>&& data);
            ASTBlock(ASTBlock&& block);

            std::vector<unsigned char> getSampleData();
            void setSampleData(std::vector<unsigned char> data);

            void printContents();
        };
    }
}