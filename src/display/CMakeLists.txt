#--------------------------------------- Display ---------------------------------------

add_library(display OBJECT "")

target_sources(display  
    PUBLIC 
        display.hpp
        display.cpp
)

target_link_libraries(display PRIVATE printable)

set_target_properties(display
    PROPERTIES 
        PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/display.hpp"
)

target_include_directories(display
    PUBLIC  
         ${CMAKE_CURRENT_SOURCE_DIR}
)
