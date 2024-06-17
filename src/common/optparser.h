#pragma once

#include <memory>
#include <string>
#include <vector>
#include <iostream>

namespace rewiind
{
    namespace common
    {
        class OptParser
        {
        private:
            /* 
             * Defined options : help (0), read (1), convert (2), output (3)
            */
            const std::vector<char> opts_ = {'h', 'r', 'c', 'o'};
            const int opts_count_ = 4;
            
            int argc_;
            std::vector<std::string> argv_;

            std::string parseerr_;

            /*
             * Each index defines the position of the option in the argv list
             * Defaults to -1 (not found)
             */
            std::vector<int> optspos_;

            /*
             * Position of argument for the file/directory to read.
             * Defaults to -1 (not found).
            */  
            int rpath_arg_ = -1;

            /*
             * Position of argument for the file/directory to convert.
             * Defaults to -1 (not found).
            */  
            int cpath_arg_ = -1;

            /*
             * Position of argument for the output file.
             * Defaults to -1 (not found).
            */  
            int out_arg_ = -1;

            bool parseOption(const std::string opt, int argv_index, int opt_index);

            inline int getOptionPos(int index) { return this->optspos_[index]; }
            inline bool getOptionState(int index) { return (this->optspos_[index] != -1) ? true : false; }
        
        public:
            OptParser(int argc, char* args[]);

            bool parse();

            inline const int getHOptPos() { return this->getOptionPos(0); }
            inline const int getROptPos() { return this->getOptionPos(1); }
            inline const int getCOptPos() { return this->getOptionPos(2); }
            inline const int getOOptPos() { return this->getOptionPos(3); }

            inline const bool getHOptState() { return this->getOptionState(0); }
            inline const bool getROptState() { return this->getOptionState(1); }
            inline const bool getCOptState() { return this->getOptionState(2); }
            inline const bool getOOptState() { return this->getOptionState(3); }

            inline const int getRPathArgPos() { return this->rpath_arg_; }
            inline const int getCPathArgPos() { return this->cpath_arg_; }
            inline const int getOPathArgPos() { return this->out_arg_; }

            inline const std::string getRPathArgValue() { return this->argv_[this->getRPathArgPos()]; }
            inline const std::string getCPathArgValue() { return this->argv_[this->getCPathArgPos()]; }
            inline const std::string getOPathArgValue() { return this->argv_[this->getOPathArgPos()]; }

            void printFlags();
            void printHelp();

            inline void printError() {  std::cerr << this->parseerr_ << std::endl; }
        };
    }
}
