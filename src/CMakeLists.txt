# Mosaicos :
if(NOT SHARED_LIBRARY)
    add_library(mosaicos STATIC)
else()
    add_library(mosaicos SHARED)
endif()

target_sources(mosaicos
    PRIVATE
        tema.cpp
        printables.cpp
        display.cpp
        colour.cpp
    PUBLIC FILE_SET HEADERS 
        FILES 
            tema.hpp
            printables.hpp
            display.hpp
            colour.hpp
)
 
target_include_directories(mosaicos
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${path_install}/include/mosaicos>"
)
