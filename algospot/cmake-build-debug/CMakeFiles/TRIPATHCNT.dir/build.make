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
include CMakeFiles/TRIPATHCNT.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TRIPATHCNT.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TRIPATHCNT.dir/flags.make

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o: CMakeFiles/TRIPATHCNT.dir/flags.make
CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o: ../TRIPATHCNT/TRIPATHCNT.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o -c /home/dodo/Programming/algo-projects/algospot/TRIPATHCNT/TRIPATHCNT.cpp

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algospot/TRIPATHCNT/TRIPATHCNT.cpp > CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.i

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algospot/TRIPATHCNT/TRIPATHCNT.cpp -o CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.s

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.requires:

.PHONY : CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.requires

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.provides: CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.requires
	$(MAKE) -f CMakeFiles/TRIPATHCNT.dir/build.make CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.provides.build
.PHONY : CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.provides

CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.provides.build: CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o


# Object files for target TRIPATHCNT
TRIPATHCNT_OBJECTS = \
"CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o"

# External object files for target TRIPATHCNT
TRIPATHCNT_EXTERNAL_OBJECTS =

TRIPATHCNT: CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o
TRIPATHCNT: CMakeFiles/TRIPATHCNT.dir/build.make
TRIPATHCNT: CMakeFiles/TRIPATHCNT.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TRIPATHCNT"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TRIPATHCNT.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TRIPATHCNT.dir/build: TRIPATHCNT

.PHONY : CMakeFiles/TRIPATHCNT.dir/build

CMakeFiles/TRIPATHCNT.dir/requires: CMakeFiles/TRIPATHCNT.dir/TRIPATHCNT/TRIPATHCNT.cpp.o.requires

.PHONY : CMakeFiles/TRIPATHCNT.dir/requires

CMakeFiles/TRIPATHCNT.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TRIPATHCNT.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TRIPATHCNT.dir/clean

CMakeFiles/TRIPATHCNT.dir/depend:
	cd /home/dodo/Programming/algo-projects/algospot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles/TRIPATHCNT.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TRIPATHCNT.dir/depend

