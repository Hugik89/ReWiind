#include <iostream>

#include "astheader.h"
#include "../common/filehandler.h"

using namespace rewiind;

int main(int argc, char* argv[])
{
    common::FileHandler fh;

    fh.openFile(argv[1], 1);
    common::ByteBuffer bb = fh.readFile(64);
    fh.closeFile();

    ast::ASTHeader ast_header{bb};
    ast_header.printContents();

    return 0;
}