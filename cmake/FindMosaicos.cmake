include(FindPackageHandleStandardArgs)

find_path(MOSAICOS_INCLUDE_DIRS 
        NAMES 
                mosaicos/color.hpp
                mosaicos/tema.hpp
                mosaicos/printables.hpp
                mosaicos/display.hpp 
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

