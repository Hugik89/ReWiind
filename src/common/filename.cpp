#include "filename.h"

using namespace rewiind::common;

FilenameBuilder::FilenameBuilder(): std::string("out") {}
FilenameBuilder::FilenameBuilder(const std::string& str): std::string(str) {}

void FilenameBuilder::addExtension(const std::string ext)
{
    if (ext[0] != '.') 
        this->append(".");
    this->append(ext);
}

void FilenameBuilder::removeExtension()
{
    size_t pos = this->find_last_of('.');
    if (pos != this->npos)
        this->erase(pos);
}

void FilenameBuilder::createFilename(const std::string ext)
{
    this->removeExtension();
    this->addExtension(ext);
}