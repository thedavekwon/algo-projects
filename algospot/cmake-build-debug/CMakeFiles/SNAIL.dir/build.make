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
CMAKE_COMMAND = /home/dodo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/dodo/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/181.5281.33/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/dodo/Programming/algo-projects/algospot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dodo/Programming/algo-projects/algospot/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SNAIL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SNAIL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SNAIL.dir/flags.make

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o: CMakeFiles/SNAIL.dir/flags.make
CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o: ../SNAIL/SNAIL.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o -c /home/dodo/Programming/algo-projects/algospot/SNAIL/SNAIL.cpp

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algospot/SNAIL/SNAIL.cpp > CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.i

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algospot/SNAIL/SNAIL.cpp -o CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.s

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.requires:

.PHONY : CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.requires

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.provides: CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.requires
	$(MAKE) -f CMakeFiles/SNAIL.dir/build.make CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.provides.build
.PHONY : CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.provides

CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.provides.build: CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o


# Object files for target SNAIL
SNAIL_OBJECTS = \
"CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o"

# External object files for target SNAIL
SNAIL_EXTERNAL_OBJECTS =

SNAIL: CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o
SNAIL: CMakeFiles/SNAIL.dir/build.make
SNAIL: CMakeFiles/SNAIL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SNAIL"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SNAIL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SNAIL.dir/build: SNAIL

.PHONY : CMakeFiles/SNAIL.dir/build

CMakeFiles/SNAIL.dir/requires: CMakeFiles/SNAIL.dir/SNAIL/SNAIL.cpp.o.requires

.PHONY : CMakeFiles/SNAIL.dir/requires

CMakeFiles/SNAIL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SNAIL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SNAIL.dir/clean

CMakeFiles/SNAIL.dir/depend:
	cd /home/dodo/Programming/algo-projects/algospot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles/SNAIL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SNAIL.dir/depend

