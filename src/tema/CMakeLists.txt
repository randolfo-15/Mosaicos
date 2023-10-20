#--------------------------------------- Tema ---------------------------------------

add_library(tema OBJECT "")

target_sources(tema 
    INTERFACE
        color.hpp
    PUBLIC 
        tema.hpp
        tema.cpp
)

set_target_properties(tema
    PROPERTIES 
        PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/tema.hpp;${CMAKE_CURRENT_SOURCE_DIR}/color.hpp"
)

target_include_directories(tema 
    PUBLIC  
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_SOURCE_DIR}/hrd>
)
