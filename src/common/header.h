#pragma once

#include "bytebuffer.h"

namespace rewiind
{

namespace common
{

class GenericBuffer
{
protected:
    ByteBuffer bytes;

public:
    virtual void printContents() = 0;
};

}

}