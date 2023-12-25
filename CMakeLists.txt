cmake_minimum_required(VERSION 3.27)

project(Mosaicos
        VERSION 1.0.0
        DESCRIPTION "Projeto C++ que visa criar boxes interativas via terminal"
        HOMEPAGE_URL "https://gitlab.com/Randolfo-15/dp_rag.git"
        LANGUAGES CXX
)
include(cmake/InstalationTools.cmake)

# Tipo de compilação:
set(CMAKE_BUILD_TYPE "Debug")

# Diretorio de artefatos construidos:
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Library)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Library)
option(SHARED_LIBRARY FALSE)

add_subdirectory(src)
if(EXISTS main.cpp)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE mosaicos)
target_include_directories(main PRIVATE mosaicos)

endif()

install_file_config()

# Defindo e instlado artefatos de exportação:
install_library(
        TARGETS_EXPORT 
                "mosaicos"
)

