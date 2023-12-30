#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Mosaicos::mosaicos" for configuration "Debug"
set_property(TARGET Mosaicos::mosaicos APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(Mosaicos::mosaicos PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "/data/data/com.termux/files/usr/lib/libmosaicos.a"
  )

list(APPEND _cmake_import_check_targets Mosaicos::mosaicos )
list(APPEND _cmake_import_check_files_for_Mosaicos::mosaicos "/data/data/com.termux/files/usr/lib/libmosaicos.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
