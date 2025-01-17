#include "astheader.h"

using namespace rewiind::ast;

// ### ASTHeader ### //

ASTHeader::ASTHeader(std::size_t buf_len): 
ByteBuffer(buf_len) {}

ASTHeader::ASTHeader(const std::vector<char>& data): 
ByteBuffer(data) {}

ASTHeader::ASTHeader(std::vector<char>&& data): 
ByteBuffer(std::move(data)) {}

ASTHeader::ASTHeader(ASTHeader&& temp): 
ByteBuffer(std::move(temp)) {}

const std::string ASTHeader::parseAudioFormat()
{
    const uint16_t fmt = this->getAudioFormat();
    switch (fmt)
    {
    case 0:
        return "ADPCM";
    
    case 1:
        return "PCM16";
    
    default:
        return "Unknown";
    }
}

void ASTHeader::printContents()
{
    std::cout << "# AST header contents" << std::endl;
    std::cout << "Magic number : " << this->getMagic() << std::endl;
    std::cout << "File size : " << this->getFileSize() << " bytes" << std::endl;
    std::cout << "Audio format : " << this->parseAudioFormat() << std::endl;
    std::cout << "Bit depth : " << this->getBitDepth() << std::endl;
    std::cout << "Number of channels : " << this->getChannelCount() << std::endl;
    std::cout << "Sample rate : " << this->getSampleRate() << " Hz" << std::endl;
    std::cout << "Total number of samples : " << this->getSampleCount() << std::endl;
    std::cout << "Loop start (sample count) : " << this->getLoopStart() << std::endl;
    std::cout << "Loop end (sample count) : " << this->getLoopEnd() << std::endl;
    std::cout << "First block size : " << this->getFirstBlockSize() << " bytes" << std::endl;
}

// ### BLCKHeader ### //

BLCKHeader::BLCKHeader(std::size_t buf_len):
ByteBuffer(buf_len) {}

BLCKHeader::BLCKHeader(const std::vector<char>& data):
ByteBuffer(data) {}

BLCKHeader::BLCKHeader(std::vector<char>&& data):
ByteBuffer(std::move(data)) {}

BLCKHeader::BLCKHeader(BLCKHeader&& temp):
ByteBuffer(std::move(temp)) {}

void BLCKHeader::printContents()
{
    std::cout << "Block magic number : " << this->getMagic() << std::endl;
    std::cout << "Block size (bytes) : " << this->getBlockSize() << std::endl;
}