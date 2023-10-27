cmake_minimum_required(VERSION 3.27)

project(Mosaicos
        VERSION 1.0.0
        DESCRIPTION "Projeto C++ que visa criar boxes interativas via terminal"
        HOMEPAGE_URL "https://gitlab.com/Randolfo-15/dp_rag.git"
        LANGUAGES CXX
)
include(GNUInstallDirs)

include(cmake/tools.cmake)

add_subdirectory(src)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

install_file_config()

install(
        TARGETS 
                mosaicos
        ARCHIVE 
                DESTINATION  ${CMAKE_INSTALL_LIBDIR}
                COMPONENT library
        FILE_SET HEADERS 
                COMPONENT include
                DESTINATION  ${CMAKE_INSTALL_INCLUDEDIR}/mosaicos
)

if(UNIX)
        set(path_config "/lib")
else()
        set(path_config " ${CMAKE_INSTALL_LIBDIR}")
endif()

install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/MosaicosConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/MosaicosConfigVersion.cmake"
        DESTINATION ${path_config}/cmake/Mosaicos
)
