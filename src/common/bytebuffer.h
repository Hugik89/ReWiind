#pragma once

#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include <iostream>

namespace rewiind
{
    namespace common
    {
        class ByteBuffer
        {
        private:
            std::vector<unsigned char> getRawBytes(std::size_t offset, std::size_t size);
            void setRawBytes(std::size_t offset, std::vector<unsigned char> data);

        protected:
            std::vector<char> buffer;

        public:
            // Must define base constructor
            ByteBuffer();

            ByteBuffer(std::size_t buf_len);
            ByteBuffer(const std::vector<char>& buf);
            ByteBuffer(std::vector<char>&& buf);
            ByteBuffer(ByteBuffer& copy);

            const std::string readString(std::size_t start, std::size_t end);
            const uint8_t readUint8(std::size_t offset);
            const uint16_t readUint16(std::size_t offset);
            const uint32_t readUint32(std::size_t offset);

            void writeString(std::size_t offset, std::string data);
            void writeUint8(std::size_t offset, uint8_t data);

            void writeUint16LE(std::size_t offset, uint16_t data);
            void writeUint32LE(std::size_t offset, uint32_t data);
            void writeUint16BE(std::size_t offset, uint16_t data);
            void writeUint32BE(std::size_t offset, uint32_t data);

            inline const std::vector<char> getData() { return this->buffer; }
            void setData(const std::vector<char> data);

            virtual void printContents() = 0;
        };
    }
}