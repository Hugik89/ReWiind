cmake_minimum_required(VERSION 3.28.0)
project(ReWiind VERSION 0.1.0 LANGUAGES CXX)

set(AST2WAV ast2wav)

include(CTest)
enable_testing()

add_subdirectory(src)

add_executable(${AST2WAV} src/utilities/${AST2WAV}.cpp)
target_link_libraries(${AST2WAV} astlib)
target_link_libraries(${AST2WAV} commonlib)
target_link_libraries(${AST2WAV} wavlib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
