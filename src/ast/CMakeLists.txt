cmake_minimum_required(VERSION 3.28.0)
project(ReWiind VERSION 0.1.0 LANGUAGES CXX)

include_directories(..)

set(ASTENGINE astheader.cpp)

add_library(astEngine SHARED ${ASTENGINE})