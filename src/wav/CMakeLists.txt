target_sources(wavlib
    PUBLIC
        wavheader.cpp
        wavheader.h
)

target_include_directories(wavlib PUBLIC ${CMAKE_CURRENT_LIST_DIR})