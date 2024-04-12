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
    bool openmode;

public :
    FileHandler();
    FileHandler(std::string, bool mode);

    ~FileHandler();

    void openFile(std::string filename, bool mode);
    rewiind::common::ByteBuffer readFile(std::size_t len);
    void moveFileOffset(long offset, bool origin);
    void closeFile();
};

}

}