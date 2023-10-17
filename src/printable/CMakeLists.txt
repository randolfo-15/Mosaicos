#--------------------------------------- Printables ---------------------------------------

add_library(printable OBJECT "")

target_sources(printable 
    PUBLIC 
        printables.hpp
        printables.cpp
)

target_link_libraries(printable PUBLIC tema)

target_include_directories(printable 
    PUBLIC  
        ${CMAKE_CURRENT_LIST_DIR}
)
