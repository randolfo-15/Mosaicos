#--------------------------------------- Display ---------------------------------------

add_library(display OBJECT "")

target_sources(display  
    PUBLIC 
        display.hpp
        display.cpp
)

target_link_libraries(display PRIVATE printable)

target_include_directories(display
    PUBLIC  
        ${CMAKE_CURRENT_LIST_DIR}
)
