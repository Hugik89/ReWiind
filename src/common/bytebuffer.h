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
    std::vector<char> buffer;

    std::vector<unsigned char> getRawBytes(std::size_t offset, std::size_t size);

public:
    // Base constructor
    ByteBuffer();
    ByteBuffer(const std::vector<char>& buf);

    // Copy constructor
    ByteBuffer(ByteBuffer& copy);

    const std::string BytestoString(std::size_t start, std::size_t end);
    const uint8_t BytestoUint8(std::size_t offset);
    const uint16_t BytestoUint16(std::size_t offset);
    const uint32_t BytestoUint32(std::size_t offset);
};

}

}