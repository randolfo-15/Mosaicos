# Mosaicos :
if(NOT SHARED_LIBRARY)
    add_library(mosaicos STATIC)
else()
    add_library(mosaicos SHARED)
endif()

target_sources(mosaicos
    PRIVATE
        str.cpp
        colour.cpp
        effect.cpp
        ground.cpp
        foreground.cpp
        background.cpp
        theme.cpp
        directions_rag.cpp
        #ios_rag.cpp
        #printables.cpp
        #display.cpp
        
    PUBLIC FILE_SET HEADERS 
        FILES 
            str.hpp
            colour.hpp
            effect.hpp
            ground.hpp
            foreground.hpp
            background.hpp
            theme.hpp
            directions_rag.hpp
            #printables.hpp
            #scaniables.hpp
            #display.hpp
)
 
target_include_directories(mosaicos
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${path_install}/include/mosaicos>"
)
