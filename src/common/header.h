#pragma once

namespace rewiind
{
    namespace common
    {
        class GenericHeader
        {
            public:
                virtual const std::string getMagic() = 0;
                virtual void setMagic(std::string data) = 0;
        };
    }
}
