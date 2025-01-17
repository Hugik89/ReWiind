#include "../common/filehandler.h"
#include "../common/filename.h"
#include "../common/optparser.h"
#include "../common/sampleblock.h"
#include "../ast/astheader.h"
#include "../wav/wavheader.h"

using namespace rewiind;

int main(int argc, char* argv[])
{
    common::OptParser opts{argc, argv};
    if (!opts.parse())
    {
        opts.printError();
        return 1;
    }

    if (opts.getHOptState())
    {
        opts.printHelp();
        return 0;
    }

    std::string input_file;

    if (opts.getROptState())
        input_file = opts.getRPathArgValue();
    else if (opts.getCOptState())
        input_file = opts.getCPathArgValue();
    else
    {
        // Should never get here

        std::cerr << "Panic : cannot find input file !" << std::endl;
        return 1;
    }

    common::FileHandler input{input_file, 1};
    common::FilenameBuilder output_file{};

    if (opts.getOOptState())
        output_file.setContents(opts.getOPathArgValue());
    else if (opts.getCOptState())
    {
        output_file.setContents(opts.getCPathArgValue());
        output_file.createFilename("wav");
    }

    ast::ASTHeader ast_header{input.readFile(0x40)};

    // Reader mode
    if (opts.getROptState())
    {
        ast_header.printContents();
    }

    // DONT FORGET TO REMOVE THIS WHEN EVERYTHING IS DONE !
    /*
    bool debug = false;
    if (debug)
    {
        std::size_t offset = 0x40;

        while (offset < ast_header.getFileSize()+0x40)
        {
            ast::BLCKHeader blck_header{input.readFile(0x20)};
            blck_header.printContents();

            std::cout << blck_header.readUint16(0x8) << std::endl;
            std::cout << blck_header.readUint16(0xa) << std::endl;
            std::cout << blck_header.readUint16(0xc) << std::endl;
            std::cout << blck_header.readUint16(0xe) << std::endl;
            
            offset += 0x20+(blck_header.getBlockSize()*ast_header.getChannelCount());

            input.moveFileOffset(offset,true);
        }
    }
    */

    // Converter mode
    if (opts.getCOptState())
    {
        // For now, we only support PCM data (audio format = 0x1)
        // ADPCM may require a dynamic size for WAVHeader (extra parameters)
        common::FileHandler output{output_file, 0};

        wav::RIFFHeader riff{0x0c};
        wav::WAVHeader wav_header{0x18};                            // PCM only !
        wav::WAVDataHdr wav_data_hdr{0x08};

        // ### Set header contents ### //

        uint16_t channel_count = ast_header.getChannelCount();
        uint32_t sample_rate = ast_header.getSampleRate();
        uint32_t sample_count = ast_header.getSampleCount();
        uint16_t bit_depth = ast_header.getBitDepth();

        uint32_t file_size = 0x04+0x18+0x08+(sample_count*channel_count*bit_depth/8);   // PCM only !

        riff.setMagic("RIFF");
        riff.setChunkSize(file_size);
        riff.setFormat("WAVE");

        wav_header.setMagic("fmt ");
        wav_header.setChunkSize(0x10);                              // PCM only !
        wav_header.setAudioFormat(0x01);                            // PCM only !
        wav_header.setChannelCount(channel_count);
        wav_header.setSampleRate(sample_rate);
        wav_header.setByteRate(channel_count*sample_rate*bit_depth/8);
        wav_header.setBlockAlign(channel_count*bit_depth/8);
        wav_header.setBitsSample(bit_depth);

        wav_data_hdr.setMagic("data");
        wav_data_hdr.setDataSize(sample_count*channel_count*bit_depth/8);

        // ### Write headers ### //

        output.writeFile(riff.getData());
        output.writeFile(wav_header.getData());
        output.writeFile(wav_data_hdr.getData());

        // ### Write WAV data ### //

        std::size_t input_offset = 0x40;
        uint32_t ast_filesize = ast_header.getFileSize();

        std::vector<common::SampleBlock> ast_blocks;

        while (input_offset < ast_filesize+0x40)
        {  
            ast::BLCKHeader blck_header{input.readFile(0x20)};
            uint32_t block_size = blck_header.getBlockSize();

            for (uint16_t i=0; i<channel_count; i++)
                ast_blocks.push_back(common::SampleBlock{bit_depth, input.readFile(block_size)});

            common::SampleBlock wav_data{bit_depth, static_cast<std::size_t>(block_size*channel_count)};

            // Read AST samples and write them to WAV file //
            while (wav_data.getOffset() < block_size*channel_count)
            {
                for (uint16_t i=0; i<channel_count; i++) {
                    wav_data.setSampleDataBE(ast_blocks[i].getSampleData());

                    ast_blocks[i].moveBlockOffset(bit_depth/8, true);
                    wav_data.moveBlockOffset(bit_depth/8, true);
                }
            }

            output.writeFile(wav_data.getBlock());

            for (int i=0;i<channel_count; i++)
                ast_blocks[i].clearBlock();
            ast_blocks.clear();
            wav_data.clearBlock();

            input_offset += 0x20+(block_size*channel_count);
            input.moveFileOffset(input_offset, true);
        }
    }

    return 0;
}