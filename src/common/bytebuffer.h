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
        protected:
            std::vector<char> buffer;

            /**
             * @brief Get a portion of the buffer, with contents casted to unsigned char
             * 
             * @param offset The starting position of the portion
             * @param size The amount of bytes to retrieve
             * @return `std::vector<unsigned char>`
             */
            std::vector<unsigned char> getRawBytes(std::size_t offset, std::size_t size);

            /**
             * @brief Set a portion of the buffer with the given data
             * 
             * @param offset The starting position of the subset
             * @param data The data to write into the buffer
             */
            void setRawBytes(std::size_t offset, std::vector<unsigned char> data);

        public:
            ByteBuffer(std::size_t buf_len);
            ByteBuffer(const std::vector<char>& buf);
            ByteBuffer(std::vector<char>&& buf);
            ByteBuffer(ByteBuffer& copy);
            ByteBuffer(ByteBuffer&& temp);

            /**
             * @brief Retrieve data from the buffer as a string
             * 
             * @param start Position of the first character
             * @param end Position of the last character
             * @return `const std::string` 
             */
            const std::string readString(std::size_t start, std::size_t end);

            /**
             * @brief Retrieve data from the buffer as an unsigned char
             * 
             * @param offset Position of the data inside the buffer
             * @return `const uint8_t` 
             */
            inline const uint8_t readUint8(std::size_t offset) { return static_cast<uint8_t>(this->buffer[offset]); }

            /**
             * @brief Retrieve data from the buffer as an unsigned short
             * 
             * @param offset Position of the data inside the buffer
             * @return `const uint16_t` 
             */
            const uint16_t readUint16(std::size_t offset);

            /**
             * @brief Retrieve data from the buffer as an unsigned int
             * 
             * @param offset Position of the data inside the buffer
             * @return `const uint32_t` 
             */
            const uint32_t readUint32(std::size_t offset);

            /**
             * @brief Write string content to the buffer
             * 
             * @param offset Starting position inside the buffer
             * @param data The string data to write into the buffer
             */
            void writeString(std::size_t offset, std::string data);

            /**
             * @brief Write unsigned char value to the buffer
             * 
             * @param offset Starting position inside the buffer
             * @param data The unsigned char value to write to the buffer
             */
            void writeUint8(std::size_t offset, uint8_t data);

            /**
             * @brief Write unsigned short value to the buffer,
             * with little-endian sorting
             * 
             * @param offset Starting position inside the buffer
             * @param data The unsigned short value to write to the buffer
             */
            void writeUint16LE(std::size_t offset, uint16_t data);

            /**
             * @brief Write unsigned short value to the buffer,
             * with big-endian sorting
             * 
             * @param offset Starting position inside the buffer
             * @param data The unsigned short value to write to the buffer
             */
            void writeUint16BE(std::size_t offset, uint16_t data);

            /**
             * @brief Write unsigned int value to the buffer,
             * with little-endian sorting
             * 
             * @param offset Starting position inside the buffer
             * @param data The unsigned int value to write to the buffer
             */
            void writeUint32LE(std::size_t offset, uint32_t data);

            /**
             * @brief Write unsigned int value to the buffer,
             * with big-endian sorting
             * 
             * @param offset Starting position inside the buffer
             * @param data The unsigned int value to write to the buffer
             */
            void writeUint32BE(std::size_t offset, uint32_t data);

            inline const std::vector<char> getData() { return this->buffer; }
            inline void setData(const std::vector<char> data) { for (auto it: data) this->buffer.push_back(it); }
        };
    }
}