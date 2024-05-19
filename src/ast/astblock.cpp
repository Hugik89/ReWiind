#include "astblock.h"

using namespace rewiind::ast;

// ### BLCKHeader ### //

BLCKHeader::BLCKHeader(std::vector<char>& data): ByteBuffer(data) {}
BLCKHeader::BLCKHeader(std::vector<char>&& data): ByteBuffer(data) {}

void BLCKHeader::printContents()
{
    std::cout << "Block magic number : " << this->getMagic() << std::endl;
    std::cout << "Block size (bytes) : " << this->getBlockSize() << std::endl;
}

// ### ASTBlock ### //

ASTBlock::ASTBlock(uint16_t bit_depth, std::vector<char>& data): bytes_per_sample_(bit_depth/8), ByteBuffer(data) {}
ASTBlock::ASTBlock(uint16_t bit_depth, std::vector<char>&& data) : bytes_per_sample_(bit_depth/8), ByteBuffer(data) {}