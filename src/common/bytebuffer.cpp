#include "bytebuffer.h"

using namespace rewiind::common;

// ### ByteBuffer ### //

ByteBuffer::ByteBuffer() {}
ByteBuffer::ByteBuffer(const std::vector<char>& buf) { this->buffer = std::move(buf); }
ByteBuffer::ByteBuffer(std::vector<char>&& buf) { this->buffer = std::move(buf); }
ByteBuffer::ByteBuffer(ByteBuffer& copy) { this->buffer = copy.buffer; }

const std::string ByteBuffer::readString(std::size_t start, std::size_t end)
{
    std::string out;

    for (auto it = this->buffer.begin()+start; it != this->buffer.begin()+end; it++)
        out.push_back(*it);

    return out;
}

const uint8_t ByteBuffer::readUint8(std::size_t offset)
{
    return static_cast<uint8_t>(this->buffer[offset]);
}

const uint16_t ByteBuffer::readUint16(std::size_t offset)
{
    std::vector<unsigned char> raw = this->getRawBytes(offset, 2);
    return (raw[0] << 8 | raw[1]);
}

const uint32_t ByteBuffer::readUint32(std::size_t offset)
{
    std::vector<unsigned char> raw = this->getRawBytes(offset, 4);
    return (raw[0] << 24 | raw[1] << 16 | raw[2] << 8 | raw[3]);
}

std::vector<unsigned char> ByteBuffer::getRawBytes(std::size_t offset, std::size_t size)
{
    std::vector<unsigned char> raw;
    raw.reserve(size);

    for (int i=0; i<size; i++)
        raw[i] = static_cast<unsigned char>(this->buffer[offset+i]);

    return raw;
}

void ByteBuffer::writeString(std::size_t offset, std::string data)
{
    std::vector<unsigned char> raw;
    raw.reserve(data.length());

    for (auto it : data)
        raw.push_back(static_cast<unsigned char>(it));
    
    this->setRawBytes(offset, raw);
}

void ByteBuffer::writeUint8(std::size_t offset, uint8_t data)
{
    std::vector<unsigned char> raw;
    raw.reserve(1);

    this->buffer.push_back(static_cast<unsigned char>(data));
    this->setRawBytes(offset, raw);
}

void ByteBuffer::writeUint16(std::size_t offset, uint16_t data)
{
    std::vector<unsigned char> raw;
    raw.reserve(2);

    for (int i=1; i>=0; i--)
        raw.push_back(static_cast<unsigned char>((data >> (8*i))));
    
    this->setRawBytes(offset, raw);
}

void ByteBuffer::writeUint32(std::size_t offset, uint32_t data)
{
    std::vector<unsigned char> raw;
    raw.reserve(4);

    for (int i=3; i>=0; i--)
        raw.push_back(static_cast<unsigned char>((data >> (8*i))));
    
    this->setRawBytes(offset, raw);
}

void ByteBuffer::setRawBytes(std::size_t offset, std::vector<unsigned char> data)
{
    for (int i=0; i<data.size(); i++)
        this->buffer[offset+i] = data[i];
}