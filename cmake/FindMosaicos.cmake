include(FindPackageHandleStandardArgs)

find_path(MOSAICOS_INCLUDE_DIRS 
        NAMES 
                mosaicos/str_rag.hpp
                mosaicos/color_rag.hpp
                mosaicos/effect_rag.hpp
                mosaicos/ground_rag.hpp
                mosaicos/background_rag.hpp 
                mosaicos/foreground_rag.hpp 
                mosaicos/theme_rag.hpp 
                mosaicos/directions_rag.hpp
                mosaicos/clear_rag.hpp
                mosaicos/display_rag.hpp 
        HINTS 
                "${CMAKE_SOURCE_DIR}/project")

find_library(MOSAICOS_LIBRARIES 
        NAMES 
                mosaicos 
        HINTS 
                "${CMAKE_SOURCE_DIR}/project"
)

find_package_handle_standard_args(Mosaicos 
        REQUIRED_VARS
                MOSAICOS_INCLUDE_DIRS
                MOSAICOS_LIBRARIES
        VERSION_VAR ${PROJECT_VERSION}
)

