# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/dodo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dodo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5087.36/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dodo/Programming/algo-projects/uva

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dodo/Programming/algo-projects/uva/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/answer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/answer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/answer.dir/flags.make

CMakeFiles/answer.dir/507/answer.cpp.o: CMakeFiles/answer.dir/flags.make
CMakeFiles/answer.dir/507/answer.cpp.o: ../507/answer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/uva/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/answer.dir/507/answer.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/answer.dir/507/answer.cpp.o -c /home/dodo/Programming/algo-projects/uva/507/answer.cpp

CMakeFiles/answer.dir/507/answer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/answer.dir/507/answer.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/uva/507/answer.cpp > CMakeFiles/answer.dir/507/answer.cpp.i

CMakeFiles/answer.dir/507/answer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/answer.dir/507/answer.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/uva/507/answer.cpp -o CMakeFiles/answer.dir/507/answer.cpp.s

CMakeFiles/answer.dir/507/answer.cpp.o.requires:

.PHONY : CMakeFiles/answer.dir/507/answer.cpp.o.requires

CMakeFiles/answer.dir/507/answer.cpp.o.provides: CMakeFiles/answer.dir/507/answer.cpp.o.requires
	$(MAKE) -f CMakeFiles/answer.dir/build.make CMakeFiles/answer.dir/507/answer.cpp.o.provides.build
.PHONY : CMakeFiles/answer.dir/507/answer.cpp.o.provides

CMakeFiles/answer.dir/507/answer.cpp.o.provides.build: CMakeFiles/answer.dir/507/answer.cpp.o


# Object files for target answer
answer_OBJECTS = \
"CMakeFiles/answer.dir/507/answer.cpp.o"

# External object files for target answer
answer_EXTERNAL_OBJECTS =

answer: CMakeFiles/answer.dir/507/answer.cpp.o
answer: CMakeFiles/answer.dir/build.make
answer: CMakeFiles/answer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/uva/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable answer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/answer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/answer.dir/build: answer

.PHONY : CMakeFiles/answer.dir/build

CMakeFiles/answer.dir/requires: CMakeFiles/answer.dir/507/answer.cpp.o.requires

.PHONY : CMakeFiles/answer.dir/requires

CMakeFiles/answer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/answer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/answer.dir/clean

CMakeFiles/answer.dir/depend:
	cd /home/dodo/Programming/algo-projects/uva/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/uva /home/dodo/Programming/algo-projects/uva /home/dodo/Programming/algo-projects/uva/cmake-build-debug /home/dodo/Programming/algo-projects/uva/cmake-build-debug /home/dodo/Programming/algo-projects/uva/cmake-build-debug/CMakeFiles/answer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/answer.dir/depend

