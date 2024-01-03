# Install script for directory: /data/data/com.termux/files/home/Mosaicos

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/data/data/com.termux/files/usr/bin/llvm-objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/data/data/com.termux/files/home/Mosaicos/build/src/cmake_install.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/data/data/com.termux/files/usr/lib/cmake/Mosaicos/MosaicosConfig.cmake;/data/data/com.termux/files/usr/lib/cmake/Mosaicos/MosaicosConfigVersion.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/data/data/com.termux/files/usr/lib/cmake/Mosaicos" TYPE FILE FILES
    "/data/data/com.termux/files/home/Mosaicos/build/Library/MosaicosConfig.cmake"
    "/data/data/com.termux/files/home/Mosaicos/build/Library/MosaicosConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "lib" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/data/data/com.termux/files/usr/lib/libmosaicos.a")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/data/data/com.termux/files/usr/lib" TYPE STATIC_LIBRARY FILES "/data/data/com.termux/files/home/Mosaicos/build/Library/libmosaicos.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "head" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/data/data/com.termux/files/usr/include/mosaicos/gd_rag.hpp;/data/data/com.termux/files/usr/include/mosaicos/str.hpp;/data/data/com.termux/files/usr/include/mosaicos/colour.hpp;/data/data/com.termux/files/usr/include/mosaicos/effect.hpp;/data/data/com.termux/files/usr/include/mosaicos/ground.hpp;/data/data/com.termux/files/usr/include/mosaicos/foreground.hpp;/data/data/com.termux/files/usr/include/mosaicos/background.hpp;/data/data/com.termux/files/usr/include/mosaicos/theme.hpp;/data/data/com.termux/files/usr/include/mosaicos/directions_rag.hpp;/data/data/com.termux/files/usr/include/mosaicos/clear_rag.hpp;/data/data/com.termux/files/usr/include/mosaicos/display_rag.hpp")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/data/data/com.termux/files/usr/include/mosaicos" TYPE FILE FILES
    "/data/data/com.termux/files/home/Mosaicos/src/gd_rag.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/str.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/colour.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/effect.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/ground.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/foreground.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/background.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/theme.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/directions_rag.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/clear_rag.hpp"
    "/data/data/com.termux/files/home/Mosaicos/src/display_rag.hpp"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget.cmake"
         "/data/data/com.termux/files/home/Mosaicos/build/CMakeFiles/Export/90f3541046061d73a952b869545457c5/mosaicosTarget.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget.cmake")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/data/data/com.termux/files/usr/lib/cmake/Mosaicos" TYPE FILE FILES "/data/data/com.termux/files/home/Mosaicos/build/CMakeFiles/Export/90f3541046061d73a952b869545457c5/mosaicosTarget.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
     "/data/data/com.termux/files/usr/lib/cmake/Mosaicos/mosaicosTarget-release.cmake")
    if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
      message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
    endif()
    file(INSTALL DESTINATION "/data/data/com.termux/files/usr/lib/cmake/Mosaicos" TYPE FILE FILES "/data/data/com.termux/files/home/Mosaicos/build/CMakeFiles/Export/90f3541046061d73a952b869545457c5/mosaicosTarget-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/data/data/com.termux/files/home/Mosaicos/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
