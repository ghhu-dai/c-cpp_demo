# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/dai/cpp/cpp进阶/src1-cmake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dai/cpp/cpp进阶/src1-cmake/build

# Include any dependencies generated for this target.
include CMakeFiles/2-2-3-1-r-move.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/2-2-3-1-r-move.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/2-2-3-1-r-move.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/2-2-3-1-r-move.dir/flags.make

CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o: CMakeFiles/2-2-3-1-r-move.dir/flags.make
CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o: ../2-2-3-1-r-move.cpp
CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o: CMakeFiles/2-2-3-1-r-move.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o -MF CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o.d -o CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o -c /home/dai/cpp/cpp进阶/src1-cmake/2-2-3-1-r-move.cpp

CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dai/cpp/cpp进阶/src1-cmake/2-2-3-1-r-move.cpp > CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.i

CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dai/cpp/cpp进阶/src1-cmake/2-2-3-1-r-move.cpp -o CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.s

# Object files for target 2-2-3-1-r-move
2__2__3__1__r__move_OBJECTS = \
"CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o"

# External object files for target 2-2-3-1-r-move
2__2__3__1__r__move_EXTERNAL_OBJECTS =

2-2-3-1-r-move: CMakeFiles/2-2-3-1-r-move.dir/2-2-3-1-r-move.cpp.o
2-2-3-1-r-move: CMakeFiles/2-2-3-1-r-move.dir/build.make
2-2-3-1-r-move: CMakeFiles/2-2-3-1-r-move.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 2-2-3-1-r-move"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/2-2-3-1-r-move.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/2-2-3-1-r-move.dir/build: 2-2-3-1-r-move
.PHONY : CMakeFiles/2-2-3-1-r-move.dir/build

CMakeFiles/2-2-3-1-r-move.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/2-2-3-1-r-move.dir/cmake_clean.cmake
.PHONY : CMakeFiles/2-2-3-1-r-move.dir/clean

CMakeFiles/2-2-3-1-r-move.dir/depend:
	cd /home/dai/cpp/cpp进阶/src1-cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dai/cpp/cpp进阶/src1-cmake /home/dai/cpp/cpp进阶/src1-cmake /home/dai/cpp/cpp进阶/src1-cmake/build /home/dai/cpp/cpp进阶/src1-cmake/build /home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles/2-2-3-1-r-move.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/2-2-3-1-r-move.dir/depend

