#include <iostream>

#include "src/ast/asthdr.h"
#include "src/common/filehandler.h"

int main(int argc, char* argv[])
{
    rewiind::common::FileHandler fh;

    fh.openFile(argv[1], 1);
    rewiind::common::ByteBuffer bb = fh.readFile(64);
    fh.closeFile();

    rewiind::ast::ASTHeader ast_header{bb};

    std::cout << ast_header.getMagic() << std::endl;

    std::cout << bb.BytestoUint32(4) << std::endl;
    std::cout << bb.BytestoUint16(8) << std::endl;

    return 0;
}