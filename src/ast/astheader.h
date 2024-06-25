#pragma once

#include <memory>
#include <string>

#include "../common/header.h"
#include "../common/bytebuffer.h"

namespace rewiind 
{
    namespace ast 
    {
        class ASTHeader : public common::ByteBuffer, common::GenericHeader
        {
        public:
            /**
             * @brief Construct a new ASTHeader object
             * 
             * @param buf_len Length of .ast file header
             */
            ASTHeader(std::size_t buf_len);

            /**
             * @brief Construct a new ASTHeader object
             * 
             * @param data The header data to copy
             */
            ASTHeader(const std::vector<char>& data);

            /**
             * @brief Construct a new ASTHeader object
             * 
             * @param data The header data to move
             */
            ASTHeader(std::vector<char>&& data);

            /**
             * @brief Move constructor for new ASTHeader object
             * 
             * @param temp The ASTHeader object to move
             */
            ASTHeader(ASTHeader&& temp);

            /**
             * @brief Get the <em>magic number</em> field from a .ast file header
             * 
             * @return `const std::string` 
             */
            inline const std::string getMagic() { return this->readString(0x00, 0x04); }

            /**
             * @brief Get the <em>file size</em> field from a .ast file header
             * 
             * @return `const uint32_t`
             */
            inline const uint32_t getFileSize() { return this->readUint32(0x04); }

            /**
             * @brief Get the <em>audio format</em> field from a .ast file header
             * 
             * @return `const uint16_t`
             */
            inline const uint16_t getAudioFormat() { return this->readUint16(0x08); }

            /**
             * @brief Get the <em>bit depth</em> field from a .ast file header
             * 
             * @return `const uint16_t` 
             */
            inline const uint16_t getBitDepth() { return this->readUint16(0x0a); }

            /**
             * @brief Get the <em>number of channels</em> field from a .ast file header
             * 
             * @return `const uint16_t`
             */
            inline const uint16_t getChannelCount() { return this->readUint16(0x0c); }

            /**
             * @brief Get the <em>sample rate</em> field from a .ast file header
             * 
             * @return `const uint32_t` 
             */
            inline const uint32_t getSampleRate() { return this->readUint32(0x10); }

            /**
             * @brief Get the <em>sample count</em> field from a .ast file header
             * 
             * @return `const uint32_t` 
             */
            inline const uint32_t getSampleCount() { return this->readUint32(0x14); }

            /**
             * @brief Get the <em>loop start</em> field from a .ast file header
             * 
             * @return `const uint32_t`
             */
            inline const uint32_t getLoopStart() { return this->readUint32(0x18); }

            /**
             * @brief Get the <em>loop end</em> field from a .ast file header
             * 
             * @return `const uint32_t` 
             */
            inline const uint32_t getLoopEnd() { return this->readUint32(0x1c); }

            /**
             * @brief Get the <em>first block size</em> field from a .ast file header
             * 
             * @return const uint32_t 
             */
            inline const uint32_t getFirstBlockSize() { return this->readUint32(0x20); }

            /**
             * @brief Set the <em>magic number</em> field of a .ast file header
             * 
             * @param data Value for magic number, must be "STRM"
             */
            inline void setMagic(std::string data) { this->writeString(0x00, data); }

            /**
             * @brief Set the <em>file size</em> field of a .ast file header
             * 
             * @param data Value for file size
             */
            inline void setFileSize(uint32_t data) { this->writeUint32Reverse(0x04, data); }

            /**
             * @brief Set the <em>audio format</em> field of a .ast file header
             * 
             * @param data Value for audio format
             */
            inline void setAudioFormat(uint16_t data) { this->writeUint16Reverse(0x08, data); }

            /**
             * @brief Set the <em>bit depth</em> field of a .ast file header
             * 
             * @param data Value for bit depth
             */
            inline void setBitDepth(uint16_t data) { this->writeUint16Reverse(0x0a, data); }

            /**
             * @brief Set the <em>number of channels</em> field of a .ast file header
             * 
             * @param data Value for number of channels
             */
            inline void setChannelCount(uint16_t data) { this->writeUint16Reverse(0x0c, data); }

            /**
             * @brief Set the <em>sample rate</em> field of a .ast file header
             * 
             * @param data Value for sample rate
             */
            inline void setSampleRate(uint32_t data) { this->writeUint32Reverse(0x10, data); }

            /**
             * @brief Set the <em>sample count</em> field of a .ast file header
             * 
             * @param data Value for sample count
             */
            inline void setSampleCount(uint32_t data) { this->writeUint32Reverse(0x14, data); }

            /**
             * @brief Set the <em>loop start</em> field of a .ast file header
             * 
             * @param data Value for loop start
             */
            inline void setLoopStart(uint32_t data) { this->writeUint32Reverse(0x18, data); }

            /**
             * @brief Set the <em>loop end</em> field of a .ast file header
             * 
             * @param data Value for loop end
             */
            inline void setLoopEnd(uint32_t data) { this->writeUint32Reverse(0x1c, data); }

            /**
             * @brief Set the <em>first block size</em> field of a .ast file header
             * 
             * @param data Value for first block size
             */
            inline void setFirstBlockSize(uint32_t data) { this->writeUint32Reverse(0x20, data); }

            /**
             * @brief Returns a string describing the type of audio format 
             * 
             * @return `const std::string` 
             */
            const std::string parseAudioFormat();

            /**
             * @brief Prints the fields of a .ast file header and their associated values
             * 
             */
            void printContents();
        };

        class BLCKHeader : public common::ByteBuffer, public common::GenericHeader
        {   
        public:
            /**
             * @brief Construct a new BLCKHeader object
             * 
             * @param buf_len Length of .ast block header
             */
            BLCKHeader(std::size_t buf_len);

            /**
             * @brief Construct a new BLCKHeader object
             * 
             * @param data The block header data to copy
             */
            BLCKHeader(const std::vector<char>& data);

            /**
             * @brief Construct a new BLCKHeader object
             * 
             * @param data The block header data to move
             */
            BLCKHeader(std::vector<char>&& data);

            /**
             * @brief Move constructor for new BLCKHeader object
             * 
             * @param copy The BLCKHeader object to move
             */
            BLCKHeader(BLCKHeader&& temp);

            /**
             * @brief Get the <em>magic number</em> field from a .ast block header
             * 
             * @return const std::string 
             */
            inline const std::string getMagic() { return this->readString(0x00, 0x04); }

            /**
             * @brief Get the <em>block size</em> field from a .ast block header
             * 
             * @return const uint32_t 
             */
            inline const uint32_t getBlockSize() { return this->readUint32(0x04); }

            /**
             * @brief Set the <em>magic number</em> field of a .ast block header
             * 
             * @param data Value for magic number, must be "BLCK"
             */
            inline void setMagic(std::string data) { this->writeString(0x00, data); }

            /**
             * @brief Set the <em>block size</em> field of a .ast block header
             * 
             * @param data Value for block size
             */
            inline void setBlockSize(uint32_t data) { this->writeUint32Reverse(0x04, data); }

            /**
             * @brief Prints the fields of a .ast block header and their associated values
             * 
             */
            void printContents();
        };
    }
}