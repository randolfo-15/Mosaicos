cmake_minimum_required(VERSION 3.24)

project(Display LANGUAGES CXX)

add_subdirectory(source)

install(TARGETS Dp_stc DESTINATION ${CMAKE_SOURCE_DIR})
