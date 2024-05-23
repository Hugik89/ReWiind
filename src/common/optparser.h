#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>

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
            int getOptionPos(int index);
            bool getOptionState(int index);
        
        public:
            OptParser(int argc, char* args[]);

            bool parse();

            const int getHOptPos();
            const int getROptPos();
            const int getCOptPos();
            const int getOOptPos();

            const bool getHOptState();
            const bool getROptState();
            const bool getCOptState();
            const bool getOOptState();

            const int getRPathArgPos();
            const int getCPathArgPos();
            const int getOPathArgPos();

            const std::string getRPathArgValue();
            const std::string getCPathArgValue();
            const std::string getOPathArgValue();

            void printFlags();
            void printHelp();
            void printError();
        };
    }
}
