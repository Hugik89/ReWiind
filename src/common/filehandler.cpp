#include "filehandler.h"

using namespace rewiind::common;

FileHandler::FileHandler() {}

FileHandler::FileHandler(std::string filename, bool mode):
openmode_(mode)
{
    this->openFile(filename, this->openmode_);
}

FileHandler::~FileHandler()
{
    if (this->filestream.is_open())
        this->closeFile();
}

void FileHandler::openFile(std::string filename, bool mode)
{
    if (this->filestream.is_open())
        return;
    
    if (this->openmode_)
        this->filestream.open(filename, (std::ios::in | std::ios::binary));
    else
        this->filestream.open(filename, (std::ios::out | std::ios::binary));

    if (!this->filestream.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
        std::exit(-1);
    }
}

void FileHandler::closeFile() { this->filestream.close(); }

std::vector<char> FileHandler::readFile(std::size_t len)
{
    std::vector<char> buffer;
    buffer.resize(len);
    
    this->filestream.read(buffer.data(), len);

    return buffer;
}

inline
void FileHandler::writeFile(std::vector<char> buffer)
{
    this->filestream.write(buffer.data(), buffer.size());
}

void FileHandler::moveFileOffset(long offset, bool origin)
{
    if (this->openmode_)
        if (origin)
            this->filestream.seekg(offset, std::ios::beg);
        else
            this->filestream.seekg(offset, std::ios::cur);
    else
        if (origin)
            this->filestream.seekp(offset, std::ios::beg);
        else
            this->filestream.seekp(offset, std::ios::cur);
}