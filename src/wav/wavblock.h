#pragma once

#include <memory>
#include <string>
#include <iterator>

#include "../common/header.h"
#include "../common/bytebuffer.h"

namespace rewiind
{
    namespace wav
    {
        class WAVBlock : public common::ByteBuffer
        {
        public:
            WAVBlock(std::size_t size);

            void clearData();

            void printContents();
        };
    }
}