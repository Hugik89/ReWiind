#include "sampleblock.h"

using namespace rewiind::common;

SampleBlock::SampleBlock(uint16_t bit_depth, std::size_t buf_len): 
bytes_per_sample_(bit_depth/8), offset_(0) 
{ this->data_.resize(buf_len, 0); }

SampleBlock::SampleBlock(uint16_t bit_depth, std::vector<char>& copy):
bytes_per_sample_(bit_depth/8), offset_(0), data_(copy) {}

SampleBlock::SampleBlock(uint16_t bit_depth, std::vector<char>&& temp):
bytes_per_sample_(bit_depth/8), offset_(0), data_(std::move(temp)) {}

SampleBlock::SampleBlock(SampleBlock&& temp): 
bytes_per_sample_(temp.bytes_per_sample_), offset_(0), data_(std::move(temp.data_)) 
{}

void SampleBlock::moveBlockOffset(std::size_t off, bool where)
{
    if (where)  this->offset_ += off;
    else        this->offset_ -= off;
}

const std::vector<char> SampleBlock::getSampleData()
{
    std::vector<char> sample;

    for (std::size_t i=0; i<this->bytes_per_sample_; i++)
        sample.push_back(this->data_[this->offset_+i]);
    
    return sample;
}

void SampleBlock::setSampleDataLE(const std::vector<char> data)
{
    for (std::size_t i=0; i<this->bytes_per_sample_; i++)
        this->data_[this->offset_+i] = data[i];
}

void SampleBlock::setSampleDataBE(const std::vector<char> data)
{
    for (std::size_t i=0; i<this->bytes_per_sample_; i++)
        this->data_[this->offset_+i] = data[data.size()-i-1];
}