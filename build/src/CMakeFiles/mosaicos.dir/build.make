# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/randolfo/Documentos/Mosaicos

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/randolfo/Documentos/Mosaicos/build

# Include any dependencies generated for this target.
include src/CMakeFiles/mosaicos.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/mosaicos.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/mosaicos.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/mosaicos.dir/flags.make

src/CMakeFiles/mosaicos.dir/str.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/str.cpp.o: /home/randolfo/Documentos/Mosaicos/src/str.cpp
src/CMakeFiles/mosaicos.dir/str.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/mosaicos.dir/str.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/str.cpp.o -MF CMakeFiles/mosaicos.dir/str.cpp.o.d -o CMakeFiles/mosaicos.dir/str.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/str.cpp

src/CMakeFiles/mosaicos.dir/str.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/str.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/str.cpp > CMakeFiles/mosaicos.dir/str.cpp.i

src/CMakeFiles/mosaicos.dir/str.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/str.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/str.cpp -o CMakeFiles/mosaicos.dir/str.cpp.s

src/CMakeFiles/mosaicos.dir/colour.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/colour.cpp.o: /home/randolfo/Documentos/Mosaicos/src/colour.cpp
src/CMakeFiles/mosaicos.dir/colour.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/mosaicos.dir/colour.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/colour.cpp.o -MF CMakeFiles/mosaicos.dir/colour.cpp.o.d -o CMakeFiles/mosaicos.dir/colour.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/colour.cpp

src/CMakeFiles/mosaicos.dir/colour.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/colour.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/colour.cpp > CMakeFiles/mosaicos.dir/colour.cpp.i

src/CMakeFiles/mosaicos.dir/colour.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/colour.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/colour.cpp -o CMakeFiles/mosaicos.dir/colour.cpp.s

src/CMakeFiles/mosaicos.dir/effect.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/effect.cpp.o: /home/randolfo/Documentos/Mosaicos/src/effect.cpp
src/CMakeFiles/mosaicos.dir/effect.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/mosaicos.dir/effect.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/effect.cpp.o -MF CMakeFiles/mosaicos.dir/effect.cpp.o.d -o CMakeFiles/mosaicos.dir/effect.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/effect.cpp

src/CMakeFiles/mosaicos.dir/effect.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/effect.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/effect.cpp > CMakeFiles/mosaicos.dir/effect.cpp.i

src/CMakeFiles/mosaicos.dir/effect.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/effect.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/effect.cpp -o CMakeFiles/mosaicos.dir/effect.cpp.s

src/CMakeFiles/mosaicos.dir/ground.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/ground.cpp.o: /home/randolfo/Documentos/Mosaicos/src/ground.cpp
src/CMakeFiles/mosaicos.dir/ground.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/mosaicos.dir/ground.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/ground.cpp.o -MF CMakeFiles/mosaicos.dir/ground.cpp.o.d -o CMakeFiles/mosaicos.dir/ground.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/ground.cpp

src/CMakeFiles/mosaicos.dir/ground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/ground.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/ground.cpp > CMakeFiles/mosaicos.dir/ground.cpp.i

src/CMakeFiles/mosaicos.dir/ground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/ground.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/ground.cpp -o CMakeFiles/mosaicos.dir/ground.cpp.s

src/CMakeFiles/mosaicos.dir/foreground.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/foreground.cpp.o: /home/randolfo/Documentos/Mosaicos/src/foreground.cpp
src/CMakeFiles/mosaicos.dir/foreground.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/mosaicos.dir/foreground.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/foreground.cpp.o -MF CMakeFiles/mosaicos.dir/foreground.cpp.o.d -o CMakeFiles/mosaicos.dir/foreground.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/foreground.cpp

src/CMakeFiles/mosaicos.dir/foreground.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/foreground.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/foreground.cpp > CMakeFiles/mosaicos.dir/foreground.cpp.i

src/CMakeFiles/mosaicos.dir/foreground.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/foreground.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/foreground.cpp -o CMakeFiles/mosaicos.dir/foreground.cpp.s

src/CMakeFiles/mosaicos.dir/background.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/background.cpp.o: /home/randolfo/Documentos/Mosaicos/src/background.cpp
src/CMakeFiles/mosaicos.dir/background.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/mosaicos.dir/background.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/background.cpp.o -MF CMakeFiles/mosaicos.dir/background.cpp.o.d -o CMakeFiles/mosaicos.dir/background.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/background.cpp

src/CMakeFiles/mosaicos.dir/background.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/background.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/background.cpp > CMakeFiles/mosaicos.dir/background.cpp.i

src/CMakeFiles/mosaicos.dir/background.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/background.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/background.cpp -o CMakeFiles/mosaicos.dir/background.cpp.s

src/CMakeFiles/mosaicos.dir/theme.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/theme.cpp.o: /home/randolfo/Documentos/Mosaicos/src/theme.cpp
src/CMakeFiles/mosaicos.dir/theme.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/mosaicos.dir/theme.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/theme.cpp.o -MF CMakeFiles/mosaicos.dir/theme.cpp.o.d -o CMakeFiles/mosaicos.dir/theme.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/theme.cpp

src/CMakeFiles/mosaicos.dir/theme.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/theme.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/theme.cpp > CMakeFiles/mosaicos.dir/theme.cpp.i

src/CMakeFiles/mosaicos.dir/theme.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/theme.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/theme.cpp -o CMakeFiles/mosaicos.dir/theme.cpp.s

src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o: src/CMakeFiles/mosaicos.dir/flags.make
src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o: /home/randolfo/Documentos/Mosaicos/src/ios_rag.cpp
src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o: src/CMakeFiles/mosaicos.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o -MF CMakeFiles/mosaicos.dir/ios_rag.cpp.o.d -o CMakeFiles/mosaicos.dir/ios_rag.cpp.o -c /home/randolfo/Documentos/Mosaicos/src/ios_rag.cpp

src/CMakeFiles/mosaicos.dir/ios_rag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mosaicos.dir/ios_rag.cpp.i"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/randolfo/Documentos/Mosaicos/src/ios_rag.cpp > CMakeFiles/mosaicos.dir/ios_rag.cpp.i

src/CMakeFiles/mosaicos.dir/ios_rag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mosaicos.dir/ios_rag.cpp.s"
	cd /home/randolfo/Documentos/Mosaicos/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/randolfo/Documentos/Mosaicos/src/ios_rag.cpp -o CMakeFiles/mosaicos.dir/ios_rag.cpp.s

# Object files for target mosaicos
mosaicos_OBJECTS = \
"CMakeFiles/mosaicos.dir/str.cpp.o" \
"CMakeFiles/mosaicos.dir/colour.cpp.o" \
"CMakeFiles/mosaicos.dir/effect.cpp.o" \
"CMakeFiles/mosaicos.dir/ground.cpp.o" \
"CMakeFiles/mosaicos.dir/foreground.cpp.o" \
"CMakeFiles/mosaicos.dir/background.cpp.o" \
"CMakeFiles/mosaicos.dir/theme.cpp.o" \
"CMakeFiles/mosaicos.dir/ios_rag.cpp.o"

# External object files for target mosaicos
mosaicos_EXTERNAL_OBJECTS =

Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/str.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/colour.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/effect.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/ground.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/foreground.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/background.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/theme.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/ios_rag.cpp.o
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/build.make
Library/libmosaicos.a: src/CMakeFiles/mosaicos.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/randolfo/Documentos/Mosaicos/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX static library ../Library/libmosaicos.a"
	cd /home/randolfo/Documentos/Mosaicos/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mosaicos.dir/cmake_clean_target.cmake
	cd /home/randolfo/Documentos/Mosaicos/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mosaicos.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/mosaicos.dir/build: Library/libmosaicos.a
.PHONY : src/CMakeFiles/mosaicos.dir/build

src/CMakeFiles/mosaicos.dir/clean:
	cd /home/randolfo/Documentos/Mosaicos/build/src && $(CMAKE_COMMAND) -P CMakeFiles/mosaicos.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/mosaicos.dir/clean

src/CMakeFiles/mosaicos.dir/depend:
	cd /home/randolfo/Documentos/Mosaicos/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/randolfo/Documentos/Mosaicos /home/randolfo/Documentos/Mosaicos/src /home/randolfo/Documentos/Mosaicos/build /home/randolfo/Documentos/Mosaicos/build/src /home/randolfo/Documentos/Mosaicos/build/src/CMakeFiles/mosaicos.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/mosaicos.dir/depend

