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
include CMakeFiles/CLOCKSYNC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CLOCKSYNC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CLOCKSYNC.dir/flags.make

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o: CMakeFiles/CLOCKSYNC.dir/flags.make
CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o: ../CLOCKSYNC/CLOCKSYNC.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o -c /home/dodo/Programming/algo-projects/algospot/CLOCKSYNC/CLOCKSYNC.cpp

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algospot/CLOCKSYNC/CLOCKSYNC.cpp > CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.i

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algospot/CLOCKSYNC/CLOCKSYNC.cpp -o CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.s

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.requires:

.PHONY : CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.requires

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.provides: CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.requires
	$(MAKE) -f CMakeFiles/CLOCKSYNC.dir/build.make CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.provides.build
.PHONY : CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.provides

CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.provides.build: CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o


# Object files for target CLOCKSYNC
CLOCKSYNC_OBJECTS = \
"CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o"

# External object files for target CLOCKSYNC
CLOCKSYNC_EXTERNAL_OBJECTS =

CLOCKSYNC: CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o
CLOCKSYNC: CMakeFiles/CLOCKSYNC.dir/build.make
CLOCKSYNC: CMakeFiles/CLOCKSYNC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CLOCKSYNC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CLOCKSYNC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CLOCKSYNC.dir/build: CLOCKSYNC

.PHONY : CMakeFiles/CLOCKSYNC.dir/build

CMakeFiles/CLOCKSYNC.dir/requires: CMakeFiles/CLOCKSYNC.dir/CLOCKSYNC/CLOCKSYNC.cpp.o.requires

.PHONY : CMakeFiles/CLOCKSYNC.dir/requires

CMakeFiles/CLOCKSYNC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CLOCKSYNC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CLOCKSYNC.dir/clean

CMakeFiles/CLOCKSYNC.dir/depend:
	cd /home/dodo/Programming/algo-projects/algospot/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug /home/dodo/Programming/algo-projects/algospot/cmake-build-debug/CMakeFiles/CLOCKSYNC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CLOCKSYNC.dir/depend

