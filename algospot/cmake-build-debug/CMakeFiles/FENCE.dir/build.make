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
include CMakeFiles/FENCE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FENCE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FENCE.dir/flags.make

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o: CMakeFiles/FENCE.dir/flags.make
CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o: ../FENCE/FENCE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o -c /home/dodo/Programming/algo-projects/algospot/FENCE/FENCE.cpp

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algospot/FENCE/FENCE.cpp > CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.i

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algospot/FENCE/FENCE.cpp -o CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.s

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.requires:

.PHONY : CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.requires

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.provides: CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.requires
	$(MAKE) -f CMakeFiles/FENCE.dir/build.make CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.provides.build
.PHONY : CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.provides

CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.provides.build: CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o


# Object files for target FENCE
FENCE_OBJECTS = \
"CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o"

# External object files for target FENCE
FENCE_EXTERNAL_OBJECTS =

FENCE: CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o
FENCE: CMakeFiles/FENCE.dir/build.make
FENCE: CMakeFiles/FENCE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FENCE"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FENCE.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FENCE.dir/build: FENCE

.PHONY : CMakeFiles/FENCE.dir/build

CMakeFiles/FENCE.dir/requires: CMakeFiles/FENCE.dir/FENCE/FENCE.cpp.o.requires

.PHONY : CMakeFiles/FENCE.dir/requires

CMakeFiles/FENCE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FENCE.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FENCE.dir/clean

CMakeFiles/FENCE.dir/depend:
	cd /home/dodo/Programming/algo-projects/algospot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles/FENCE.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FENCE.dir/depend

