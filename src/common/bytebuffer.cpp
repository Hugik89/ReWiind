#include "bytebuffer.h"

using namespace rewiind::common;

ByteBuffer::ByteBuffer()
{
    
}

ByteBuffer::ByteBuffer(const std::vector<char>& buf)
{
    this->buffer = std::move(buf);
}

ByteBuffer::ByteBuffer(ByteBuffer& copy)
{
    this->buffer = copy.buffer;
}

const std::string ByteBuffer::BytestoString(std::size_t start, std::size_t end)
{
    std::string out;

    for (auto it = this->buffer.begin()+start; it != this->buffer.begin()+end; it++) {
        out.push_back(*it);
    }
    return out;
}

const uint8_t ByteBuffer::BytestoUint8(std::size_t offset)
{
    return static_cast<uint8_t>(this->buffer[offset]);
}

const uint16_t ByteBuffer::BytestoUint16(std::size_t offset)
{
    std::vector<unsigned char> raw = this->getRawBytes(offset, 2);
    return (raw[0] << 8 | raw[1]);
}

const uint32_t ByteBuffer::BytestoUint32(std::size_t offset)
{
    std::vector<unsigned char> raw = this->getRawBytes(offset, 4);
    return (raw[0] << 24 | raw[1] << 16 | raw[2] << 8 | raw[3]);
}

std::vector<unsigned char> ByteBuffer::getRawBytes(std::size_t offset, std::size_t size)
{
    std::vector<unsigned char> raw;
    raw.resize(size);

    for (int i=0; i<size; i++) {
        raw[i] = static_cast<unsigned char>(this->buffer[offset+i]);
    }

    return raw;
}