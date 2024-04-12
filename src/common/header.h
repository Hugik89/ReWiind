#pragma once

#include "bytebuffer.h"

namespace rewiind
{

namespace common
{

class GenericHeader
{
protected:
    ByteBuffer bytes;

public:
    virtual void printContents() = 0;
};

}

}