#include "asthdr.h"

#include <iterator>

using namespace rewiind::ast;

ASTHeader::ASTHeader(rewiind::common::ByteBuffer& bytebuffer)
{
    this->headerdata = std::move(bytebuffer);
}

const std::string ASTHeader::getMagic()
{
    return this->headerdata.BytestoString(0,4);
}