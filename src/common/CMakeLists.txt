target_sources(commonlib
    PUBLIC
        bytebuffer.cpp
        bytebuffer.h
        filehandler.cpp
        filehandler.h
        filename.cpp
        filename.h
        sampleblock.cpp
        sampleblock.h
        optparser.cpp
        optparser.h
)

target_include_directories(commonlib PUBLIC ${CMAKE_CURRENT_LIST_DIR})