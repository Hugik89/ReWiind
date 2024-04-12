#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "bytebuffer.h"

namespace rewiind
{

namespace common
{

class FileHandler
{
private :
    std::fstream filestream;

public :
    void openFile(std::string filename, bool mode);
    void closeFile();

    rewiind::common::ByteBuffer readFile(std::size_t len);
};

}

}