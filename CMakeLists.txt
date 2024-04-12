cmake_minimum_required(VERSION 3.28.0)
project(ReWiind VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

add_subdirectory(src/ast)
add_subdirectory(src/common)

add_executable(${PROJECT_NAME} rewiind.cpp)

target_link_libraries(${PROJECT_NAME} astEngine)
target_link_libraries(${PROJECT_NAME} commonEngine)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
