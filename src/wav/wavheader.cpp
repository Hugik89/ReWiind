#include "wavheader.h"

using namespace rewiind::common;
using namespace rewiind::wav;

RIFFHeader::RIFFHeader(std::vector<char>& data): ByteBuffer(data) {}
RIFFHeader::RIFFHeader(std::vector<char>&& data): ByteBuffer(data) {}

void RIFFHeader::printContents()
{
    std::cout << "Magic number : " << this->getMagic() << std::endl;
    std::cout << "File size (bytes) : " << this->getChunkSize() << std::endl;
    std::cout << "Format magic : " << this->getFormat() << std::endl;
}

WAVHeader::WAVHeader(std::vector<char>& data): ByteBuffer(data) {}
WAVHeader::WAVHeader(std::vector<char>&& data): ByteBuffer(data) {}

const std::string WAVHeader::parseAudioFormat()
{
    const uint16_t fmt = this->getAudioFormat();
    return (fmt == 0x0001) ? "PCM" : "Unknown";
}

void WAVHeader::printContents()
{
    std::cout << "Magic number : " << this->getMagic() << std::endl;
    std::cout << "Chunk size (bytes) : " << this->getChunkSize() << std::endl;
    std::cout << "Audio format : " << this->parseAudioFormat() << std::endl;
    std::cout << "Number of channels : " << this->getChannelCount() << std::endl;
    std::cout << "Sample rate : " << this->getSampleRate() << std::endl;
    std::cout << "Byte rate : " << this->getByteRate() << std::endl;
    std::cout << "Block align : " << this->getBlockAlign() << std::endl;
    std::cout << "Bits per sample : " << this->getBitsSample() << std::endl;
}

WAVDataHdr::WAVDataHdr(std::vector<char>& data) : ByteBuffer(data) {}
WAVDataHdr::WAVDataHdr(std::vector<char>&& data) : ByteBuffer(data) {}

void WAVDataHdr::printContents()
{
    std::cout << "Magic number : " << this->getMagic() << std::endl;
    std::cout << "Data size (bytes) : " << this->getDataSize() << std::endl;
}