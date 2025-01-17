#include "optparser.h"

using namespace rewiind::common;

OptParser::OptParser(int argc, char* args[]): argc_(argc)
{
    this->argv_.reserve(this->argc_);
    for (int i=0; i<this->argc_; i++)
        this->argv_.push_back(std::string(args[i]));
    
    this->optspos_.reserve(this->opts_count_);
    for (int i=0; i<this->opts_count_; i++)
        this->optspos_.push_back(-1);
}

bool OptParser::parse()
{
    bool valid_opt;

    if (this->argc_ < 2)
    {
        this->parseerr_ = "Not enough arguments (use "+this->argv_[0]+" -h for more info)";
        return false;
    }

    for (int i=1; i<this->argc_; i++)
    {
        valid_opt = false;

        if (this->argv_[i][0] == '-')                           // Options
        {
            // Zero-length option ?
            if (this->argv_[i].length() < 2)
            {
                this->parseerr_ = "Malformed option detected : "+this->argv_[i];
                return false;
            }
            
            // Check for all possible option values
            for (int j=0; j<this->opts_count_; j++)
                valid_opt |= this->parseOption(this->argv_[i], i, j);

            // Undefined option ?
            if (!valid_opt) {
                this->parseerr_ = "Unknown option detected : "+this->argv_[i];
                return false;
            }
        }
        else {                                              // Arguments
            if (i >= 2) {                                   // We must begin with an option !
                if (this->getROptPos() == i-1)
                {
                    if (this->rpath_arg_ == -1)
                    {
                        if (this->getROptPos() == this->getCOptPos())
                            this->cpath_arg_ = i;
                        this->rpath_arg_ = i;
                    }
                }
                if (this->getCOptPos() == i-1)
                {
                    if (this->cpath_arg_ == -1)
                    {
                        if (this->getROptPos() == this->getCOptPos())
                            this->rpath_arg_ = i;
                        this->cpath_arg_ = i;
                    }
                }
                if (this->getOOptPos() == i-1)
                {
                    if (this->out_arg_ == -1)
                        this->out_arg_ = i;
                }
            }
        }
    }

    /*** Various checks ***/

    // If -h, must be the only argument
    if (this->getHOptState() && this->argc_ > 2)
    {
        this->parseerr_ = "Cannot use help command with other options";
        return false;
    }

    // If -r, must have an associated input file/directory
    if (this->getROptState())
    {
        if (this->getRPathArgPos() < 0)
        {
            this->parseerr_ = "Please define an input file";
            return false;
        }
    }

    // If -c, must have an associated input file/directory
    if (this->getCOptState())
    {
        if (this->getCPathArgPos() < 0)
        {
            this->parseerr_ = "Please define an input file";
            return false;
        }
    }

    // If -r <path> -c <path>, the two arguments must be identical
    if ((this->getROptState() &&  this->getCOptState()) && (this->getROptPos() != this->getCOptPos()))
    {
        if (this->getRPathArgValue() != this->getRPathArgValue())
        {
            this->parseerr_ = "Diverging paths for -r and -c: "+this->getRPathArgValue()+"!="+this->getCPathArgValue();
            return false;
        }
    }

    // If -o, must be used with -c and associated with an output file
    if (this->getOOptState())
    {
        if (!this->getCOptState())
        {
            this->parseerr_ = "Cannot generate output file without -c option";
            return false;
        }

        if (this->out_arg_ < 0)
        {
            this->parseerr_ = "Please define an output file";
            return false;
        }
    }

    return true;
}

bool OptParser::parseOption(const std::string opt, int argv_index, int opt_index)
{
    if ((opt.find(this->opts_[opt_index]) != std::string::npos) && !this->getOptionState(opt_index)) {
        this->optspos_[opt_index] = argv_index;
        return true;
    }
    return false;
}

void OptParser::printFlags()
{
    std::cout << "-h : " << std::boolalpha << this->getHOptState() << ", pos : " << std::noboolalpha << this->getHOptPos() << std::endl;
    std::cout << "-r : " << std::boolalpha << this->getROptState() << ", pos : " << std::noboolalpha << this->getROptPos() << std::endl;
    std::cout << "-c : " << std::boolalpha << this->getCOptState() << ", pos : " << std::noboolalpha << this->getCOptPos() << std::endl;
    std::cout << "-o : " << std::boolalpha << this->getOOptState() << ", pos : " << std::noboolalpha << this->getOOptPos() << std::endl;

    std::cout << "rpath : " << this->getRPathArgPos() << std::endl;
    std::cout << "cpath : " << this->getCPathArgPos() << std::endl;
    std::cout << "out : " << this->getOPathArgPos() << std::endl;
}

void OptParser::printHelp()
{
    std::cout << "Options :" << std::endl;
    std::cout << "-h : print this section" << std::endl;
    std::cout << "-r [file] : reads the given file" << std::endl;
    std::cout << "-c [file] : converts the given file" << std::endl;
    std::cout << "-o [file] : define output file, must be used with -c" << std::endl;
}