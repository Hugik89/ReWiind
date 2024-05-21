#include "../ast/astheader.h"
#include "../ast/astblock.h"
#include "../common/filehandler.h"
#include "../common/filename.h"
#include "../common/optparser.h"

using namespace rewiind;

int main(int argc, char* argv[])
{
    common::OptParser opts{argc, argv};
    if (!opts.parse())
    {
        opts.printError();
        return 1;
    }

    /*
    common::FilenameBuilder outname{argv[1]};
    outname.createFilename("wav");

    common::FileHandler input{argv[1], 1};

    ast::ASTHeader ast_header{input.readFile(0x40)};
    */

    // ast::BLCKHeader blck_header{input.readFile(0x20)};
    // common::FileHandler output{outname, 0};

    return 0;
}