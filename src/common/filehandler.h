#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

namespace rewiind
{
    namespace common
    {
        class FileHandler
        {
        private:
            std::fstream filestream;
            bool openmode_;

        public:
            FileHandler();
            FileHandler(std::string, bool mode);

            ~FileHandler();

            void openFile(std::string filename, bool mode);
            void closeFile();

            std::vector<char> readFile(std::size_t len);
            inline void writeFile(std::vector<char> buffer) { this->filestream.write(buffer.data(), buffer.size()); }

            void moveFileOffset(long offset, bool origin);
        };
    }
}