#include <iostream>

#include "astheader.h"
#include "../common/filehandler.h"

using namespace rewiind;

int main(int argc, char* argv[])
{
    common::FileHandler fh{argv[1], 1};

    ast::ASTHeader ast_header{fh.readFile(0x40)};
    ast_header.printContents();

    return 0;
}