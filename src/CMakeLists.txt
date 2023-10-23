# Mosaicos :

 add_library(mosaico STATIC)
 
 target_sources(mosaico
    PUBLIC
        tema.cpp
        printables.cpp
        display.cpp
    PUBLIC FILE_SET HEADERS 
        FILES 
            tema.hpp
            printables.hpp
            display.hpp
            color.hpp
)
 
 target_include_directories(mosaico
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
 )
