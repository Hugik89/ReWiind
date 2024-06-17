#pragma once

#include <string>
#include <memory>

namespace rewiind
{
    namespace common
    {
        class FilenameBuilder : public std::string
        {
        private:
            void addExtension(const std::string ext);
            void removeExtension();
        
        public:
            FilenameBuilder();
            FilenameBuilder(const std::string& str);
            FilenameBuilder(std::string&& str);

            void createFilename(const std::string ext);
            
            void setContents(const std::string str);
        };
    }
}