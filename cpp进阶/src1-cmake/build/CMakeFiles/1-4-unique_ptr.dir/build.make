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
include CMakeFiles/1-4-unique_ptr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1-4-unique_ptr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1-4-unique_ptr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1-4-unique_ptr.dir/flags.make

CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o: CMakeFiles/1-4-unique_ptr.dir/flags.make
CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o: ../1-4-unique_ptr.cpp
CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o: CMakeFiles/1-4-unique_ptr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o -MF CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o.d -o CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o -c /home/dai/cpp/cpp进阶/src1-cmake/1-4-unique_ptr.cpp

CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dai/cpp/cpp进阶/src1-cmake/1-4-unique_ptr.cpp > CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.i

CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dai/cpp/cpp进阶/src1-cmake/1-4-unique_ptr.cpp -o CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.s

# Object files for target 1-4-unique_ptr
1__4__unique_ptr_OBJECTS = \
"CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o"

# External object files for target 1-4-unique_ptr
1__4__unique_ptr_EXTERNAL_OBJECTS =

1-4-unique_ptr: CMakeFiles/1-4-unique_ptr.dir/1-4-unique_ptr.cpp.o
1-4-unique_ptr: CMakeFiles/1-4-unique_ptr.dir/build.make
1-4-unique_ptr: CMakeFiles/1-4-unique_ptr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1-4-unique_ptr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/1-4-unique_ptr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1-4-unique_ptr.dir/build: 1-4-unique_ptr
.PHONY : CMakeFiles/1-4-unique_ptr.dir/build

CMakeFiles/1-4-unique_ptr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/1-4-unique_ptr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/1-4-unique_ptr.dir/clean

CMakeFiles/1-4-unique_ptr.dir/depend:
	cd /home/dai/cpp/cpp进阶/src1-cmake/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dai/cpp/cpp进阶/src1-cmake /home/dai/cpp/cpp进阶/src1-cmake /home/dai/cpp/cpp进阶/src1-cmake/build /home/dai/cpp/cpp进阶/src1-cmake/build /home/dai/cpp/cpp进阶/src1-cmake/build/CMakeFiles/1-4-unique_ptr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1-4-unique_ptr.dir/depend

