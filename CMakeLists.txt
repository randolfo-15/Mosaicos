cmake_minimum_required(VERSION 3.27)

project(Mosaicos
        VERSION 1.0.0
        DESCRIPTION "Projeto C++ que visa criar boxes interativas via terminal"
        HOMEPAGE_URL "https://gitlab.com/Randolfo-15/dp_rag.git"
        LANGUAGES CXX
)

add_subdirectory(src)

install(
        TARGETS 
                mosaico
                tema
                printable
                display
        ARCHIVE 
                DESTINATION  ${CMAKE_SOURCE_DIR}
                COMPONENT  lib
        PUBLIC_HEADER 
                DESTINATION ${CMAKE_SOURCE_DIR}/hrd
                COMPONENT dev
)
