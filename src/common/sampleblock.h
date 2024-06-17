#pragma once

#include <memory>
#include <vector>
#include <string>
#include <iterator>

namespace rewiind
{
    namespace common
    {
        class SampleBlock
        {
        protected:
            std::vector<char> data_;

            uint32_t bytes_per_sample_;
            std::size_t offset_;

        public:
            SampleBlock(uint16_t bit_depth, std::size_t buf_len);
            SampleBlock(uint16_t bit_depth, std::vector<char>& copy);
            SampleBlock(uint16_t bit_depth, std::vector<char>&& temp);
            SampleBlock(SampleBlock&& temp);

            void moveBlockOffset(std::size_t off, bool where);

            inline const std::size_t getOffset() { return this->offset_; }
            inline void setOffset(const std::size_t off) { this->offset_ = off; }
            inline void clearOffset() { this->offset_ = 0x0; }

            const std::vector<char> getSampleData();
            void setSampleDataLE(const std::vector<char> data);
            void setSampleDataBE(const std::vector<char> data);

            inline const std::vector<char> getBlock() { return this->data_; }
            inline void clearBlock() { this->data_.clear(); }
        };
    }
}