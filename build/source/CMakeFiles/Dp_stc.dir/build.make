# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /data/data/com.termux/files/usr/bin/sh

# The CMake executable.
CMAKE_COMMAND = /data/data/com.termux/files/usr/bin/cmake

# The command to remove a file.
RM = /data/data/com.termux/files/usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /data/data/com.termux/files/home/Dp_rag

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/data/com.termux/files/home/Dp_rag/build

# Include any dependencies generated for this target.
include source/CMakeFiles/Dp_stc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/CMakeFiles/Dp_stc.dir/compiler_depend.make

# Include the progress variables for this target.
include source/CMakeFiles/Dp_stc.dir/progress.make

# Include the compile flags for this target's objects.
include source/CMakeFiles/Dp_stc.dir/flags.make

source/CMakeFiles/Dp_stc.dir/display.cpp.o: source/CMakeFiles/Dp_stc.dir/flags.make
source/CMakeFiles/Dp_stc.dir/display.cpp.o: /data/data/com.termux/files/home/Dp_rag/source/display.cpp
source/CMakeFiles/Dp_stc.dir/display.cpp.o: source/CMakeFiles/Dp_stc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Dp_rag/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/CMakeFiles/Dp_stc.dir/display.cpp.o"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/Dp_stc.dir/display.cpp.o -MF CMakeFiles/Dp_stc.dir/display.cpp.o.d -o CMakeFiles/Dp_stc.dir/display.cpp.o -c /data/data/com.termux/files/home/Dp_rag/source/display.cpp

source/CMakeFiles/Dp_stc.dir/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dp_stc.dir/display.cpp.i"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Dp_rag/source/display.cpp > CMakeFiles/Dp_stc.dir/display.cpp.i

source/CMakeFiles/Dp_stc.dir/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dp_stc.dir/display.cpp.s"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Dp_rag/source/display.cpp -o CMakeFiles/Dp_stc.dir/display.cpp.s

source/CMakeFiles/Dp_stc.dir/printables.cpp.o: source/CMakeFiles/Dp_stc.dir/flags.make
source/CMakeFiles/Dp_stc.dir/printables.cpp.o: /data/data/com.termux/files/home/Dp_rag/source/printables.cpp
source/CMakeFiles/Dp_stc.dir/printables.cpp.o: source/CMakeFiles/Dp_stc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Dp_rag/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object source/CMakeFiles/Dp_stc.dir/printables.cpp.o"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/Dp_stc.dir/printables.cpp.o -MF CMakeFiles/Dp_stc.dir/printables.cpp.o.d -o CMakeFiles/Dp_stc.dir/printables.cpp.o -c /data/data/com.termux/files/home/Dp_rag/source/printables.cpp

source/CMakeFiles/Dp_stc.dir/printables.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dp_stc.dir/printables.cpp.i"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Dp_rag/source/printables.cpp > CMakeFiles/Dp_stc.dir/printables.cpp.i

source/CMakeFiles/Dp_stc.dir/printables.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dp_stc.dir/printables.cpp.s"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Dp_rag/source/printables.cpp -o CMakeFiles/Dp_stc.dir/printables.cpp.s

source/CMakeFiles/Dp_stc.dir/tema.cpp.o: source/CMakeFiles/Dp_stc.dir/flags.make
source/CMakeFiles/Dp_stc.dir/tema.cpp.o: /data/data/com.termux/files/home/Dp_rag/source/tema.cpp
source/CMakeFiles/Dp_stc.dir/tema.cpp.o: source/CMakeFiles/Dp_stc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/data/com.termux/files/home/Dp_rag/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object source/CMakeFiles/Dp_stc.dir/tema.cpp.o"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/CMakeFiles/Dp_stc.dir/tema.cpp.o -MF CMakeFiles/Dp_stc.dir/tema.cpp.o.d -o CMakeFiles/Dp_stc.dir/tema.cpp.o -c /data/data/com.termux/files/home/Dp_rag/source/tema.cpp

source/CMakeFiles/Dp_stc.dir/tema.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Dp_stc.dir/tema.cpp.i"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/data/com.termux/files/home/Dp_rag/source/tema.cpp > CMakeFiles/Dp_stc.dir/tema.cpp.i

source/CMakeFiles/Dp_stc.dir/tema.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Dp_stc.dir/tema.cpp.s"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && /data/data/com.termux/files/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/data/com.termux/files/home/Dp_rag/source/tema.cpp -o CMakeFiles/Dp_stc.dir/tema.cpp.s

# Object files for target Dp_stc
Dp_stc_OBJECTS = \
"CMakeFiles/Dp_stc.dir/display.cpp.o" \
"CMakeFiles/Dp_stc.dir/printables.cpp.o" \
"CMakeFiles/Dp_stc.dir/tema.cpp.o"

# External object files for target Dp_stc
Dp_stc_EXTERNAL_OBJECTS =

source/libDp_stc.a: source/CMakeFiles/Dp_stc.dir/display.cpp.o
source/libDp_stc.a: source/CMakeFiles/Dp_stc.dir/printables.cpp.o
source/libDp_stc.a: source/CMakeFiles/Dp_stc.dir/tema.cpp.o
source/libDp_stc.a: source/CMakeFiles/Dp_stc.dir/build.make
source/libDp_stc.a: source/CMakeFiles/Dp_stc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/data/com.termux/files/home/Dp_rag/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libDp_stc.a"
	cd /data/data/com.termux/files/home/Dp_rag/build/source && $(CMAKE_COMMAND) -P CMakeFiles/Dp_stc.dir/cmake_clean_target.cmake
	cd /data/data/com.termux/files/home/Dp_rag/build/source && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Dp_stc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/CMakeFiles/Dp_stc.dir/build: source/libDp_stc.a
.PHONY : source/CMakeFiles/Dp_stc.dir/build

source/CMakeFiles/Dp_stc.dir/clean:
	cd /data/data/com.termux/files/home/Dp_rag/build/source && $(CMAKE_COMMAND) -P CMakeFiles/Dp_stc.dir/cmake_clean.cmake
.PHONY : source/CMakeFiles/Dp_stc.dir/clean

source/CMakeFiles/Dp_stc.dir/depend:
	cd /data/data/com.termux/files/home/Dp_rag/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/data/com.termux/files/home/Dp_rag /data/data/com.termux/files/home/Dp_rag/source /data/data/com.termux/files/home/Dp_rag/build /data/data/com.termux/files/home/Dp_rag/build/source /data/data/com.termux/files/home/Dp_rag/build/source/CMakeFiles/Dp_stc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/CMakeFiles/Dp_stc.dir/depend

