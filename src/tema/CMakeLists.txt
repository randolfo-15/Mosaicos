#--------------------------------------- Tema ---------------------------------------

add_library(tema OBJECT "")

target_sources(tema 
    INTERFACE 
        color.hpp
    PUBLIC 
        tema.hpp
        tema.cpp
)

target_include_directories(tema 
    PUBLIC  
        ${CMAKE_CURRENT_LIST_DIR}
)
