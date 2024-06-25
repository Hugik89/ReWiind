#pragma once

#include <string>

namespace rewiind
{
    namespace common
    {
        /**
         * @brief Singleton for endianness check
         */
        class EndianCheck
        {
            private:
                static EndianCheck* instance;
                bool value_;

                EndianCheck() = default;
                ~EndianCheck() = default;

                void isBigEndian()
                {
                    const int i = 1;
                    value_ = (reinterpret_cast<const char*>(&i)[3] == 1);
                }
            
            public:
                EndianCheck(const EndianCheck&) = delete;
                EndianCheck(EndianCheck&&) = delete;
                EndianCheck& operator=(const EndianCheck&) = delete;

                static EndianCheck& get()
                {
                    if (instance == nullptr)
                    {
                        instance = new EndianCheck{};
                        instance->get().isBigEndian();
                    }
                    return *instance;
                }

                static void destruct()
                {
                    delete instance;
                    instance = nullptr;
                }

                inline bool getValue() { return value_; }
                inline std::string getStringValue() { return value_ ? "Big-Endian" : "Little-Endian"; }
        };
    }
}