#include "wavblock.h"

using namespace rewiind::wav;

WAVBlock::WAVBlock(std::size_t size): ByteBuffer(size) {}

void WAVBlock::clearData() { this->buffer.clear(); }

void WAVBlock::printContents() {}