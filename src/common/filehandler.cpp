#include "filehandler.h"

using namespace rewiind::common;

void FileHandler::openFile(std::string filename, bool mode)
{
    if (mode)
        this->filestream.open(filename, (std::ios::in | std::ios::binary));
    else
        this->filestream.open(filename, (std::ios::out | std::ios::binary));

    if (!this->filestream.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
        std::exit(-1);
    }
}

void FileHandler::closeFile()
{
    this->filestream.close();
}

rewiind::common::ByteBuffer FileHandler::readFile(std::size_t len)
{
    std::vector<char> buffer;
    buffer.resize(len);
    
    this->filestream.read(buffer.data(), len);

    rewiind::common::ByteBuffer bytebuffer{buffer};

    return bytebuffer;
}