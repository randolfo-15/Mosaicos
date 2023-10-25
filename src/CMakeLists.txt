# Mosaicos :

 add_library(mosaicos STATIC)
 
 target_sources(mosaicos
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
 
 
 target_include_directories(mosaicos
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_LIBDIR}"
)
