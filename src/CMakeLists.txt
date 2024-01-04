# Mosaicos :
if(NOT SHARED_LIBRARY)
    add_library(mosaicos STATIC)
else()
    add_library(mosaicos SHARED)
endif()

target_sources(mosaicos
    PRIVATE
        str.cpp
        colour.cpp
        effect.cpp
        ground.cpp
        foreground.cpp
        background.cpp
        theme.cpp
        directions.cpp
        clear.cpp
        display.cpp
        
    PUBLIC FILE_SET HEADERS 
        FILES 
            gd_rag.hpp
            str_rag.hpp
            colour_rag.hpp
            effect_rag.hpp
            ground_rag.hpp
            foreground_rag.hpp
            background_rag.hpp
            theme_rag.hpp
            directions_rag.hpp
            clear_rag.hpp
            display_rag.hpp
            
)
 
target_include_directories(mosaicos
    PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${path_install}/include/mosaicos>"
)
