#include "astblock.h"

using namespace rewiind::ast;

// ### BLCKHeader ### //

BLCKHeader::BLCKHeader(std::size_t buf_len): ByteBuffer(buf_len) {}
BLCKHeader::BLCKHeader(const std::vector<char>& data): ByteBuffer(data) {}
BLCKHeader::BLCKHeader(std::vector<char>&& data): ByteBuffer(data) {}

void BLCKHeader::printContents()
{
    std::cout << "Block magic number : " << this->getMagic() << std::endl;
    std::cout << "Block size (bytes) : " << this->getBlockSize() << std::endl;
}

// ### ASTBlock ### //

ASTBlock::ASTBlock(uint16_t bit_depth, std::size_t buf_len): bytes_per_sample_(bit_depth/8), ByteBuffer(buf_len) {}
ASTBlock::ASTBlock(uint16_t bit_depth, const std::vector<char>& data): bytes_per_sample_(bit_depth/8), ByteBuffer(data) {}
ASTBlock::ASTBlock(uint16_t bit_depth, std::vector<char>&& data): bytes_per_sample_(bit_depth/8), ByteBuffer(data) {}
ASTBlock::ASTBlock(ASTBlock&& block): bytes_per_sample_(block.bytes_per_sample_) 
{
    this->buffer = std::move(block.buffer);
}

// TO DO
std::vector<unsigned char> ASTBlock::getSampleData() {}
void ASTBlock::setSampleData(std::vector<unsigned char> data) {}

void ASTBlock::printContents() {}