#--------------------------------------- Printables ---------------------------------------

add_library(printable OBJECT "")

target_sources(printable 
    PUBLIC 
        printables.hpp
        printables.cpp
)

target_link_libraries(printable PUBLIC tema)

set_target_properties(printable
    PROPERTIES 
        PUBLIC_HEADER "${CMAKE_CURRENT_LIST_DIR}/printables.hpp"
)

target_include_directories(printable 
    PUBLIC  
        ${CMAKE_CURRENT_SOURCE_DIR}
)
