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
CMAKE_SOURCE_DIR = /home/dodo/Programming/algo-projects/algospot

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dodo/Programming/algo-projects/algospot/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/COINS.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COINS.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COINS.dir/flags.make

CMakeFiles/COINS.dir/COINS/COINS.cpp.o: CMakeFiles/COINS.dir/flags.make
CMakeFiles/COINS.dir/COINS/COINS.cpp.o: ../COINS/COINS.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COINS.dir/COINS/COINS.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/COINS.dir/COINS/COINS.cpp.o -c /home/dodo/Programming/algo-projects/algospot/COINS/COINS.cpp

CMakeFiles/COINS.dir/COINS/COINS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COINS.dir/COINS/COINS.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algospot/COINS/COINS.cpp > CMakeFiles/COINS.dir/COINS/COINS.cpp.i

CMakeFiles/COINS.dir/COINS/COINS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COINS.dir/COINS/COINS.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algospot/COINS/COINS.cpp -o CMakeFiles/COINS.dir/COINS/COINS.cpp.s

CMakeFiles/COINS.dir/COINS/COINS.cpp.o.requires:

.PHONY : CMakeFiles/COINS.dir/COINS/COINS.cpp.o.requires

CMakeFiles/COINS.dir/COINS/COINS.cpp.o.provides: CMakeFiles/COINS.dir/COINS/COINS.cpp.o.requires
	$(MAKE) -f CMakeFiles/COINS.dir/build.make CMakeFiles/COINS.dir/COINS/COINS.cpp.o.provides.build
.PHONY : CMakeFiles/COINS.dir/COINS/COINS.cpp.o.provides

CMakeFiles/COINS.dir/COINS/COINS.cpp.o.provides.build: CMakeFiles/COINS.dir/COINS/COINS.cpp.o


# Object files for target COINS
COINS_OBJECTS = \
"CMakeFiles/COINS.dir/COINS/COINS.cpp.o"

# External object files for target COINS
COINS_EXTERNAL_OBJECTS =

COINS: CMakeFiles/COINS.dir/COINS/COINS.cpp.o
COINS: CMakeFiles/COINS.dir/build.make
COINS: CMakeFiles/COINS.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COINS"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COINS.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COINS.dir/build: COINS

.PHONY : CMakeFiles/COINS.dir/build

CMakeFiles/COINS.dir/requires: CMakeFiles/COINS.dir/COINS/COINS.cpp.o.requires

.PHONY : CMakeFiles/COINS.dir/requires

CMakeFiles/COINS.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COINS.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COINS.dir/clean

CMakeFiles/COINS.dir/depend:
	cd /home/dodo/Programming/algo-projects/algospot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles/COINS.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/COINS.dir/depend

