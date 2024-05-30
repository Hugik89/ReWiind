cmake_minimum_required(VERSION 3.28.0)
project(ReWiind VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
enable_testing()

set(SOURCES astheader.cpp)
add_library(astlib SHARED ${SOURCES})