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
CMAKE_SOURCE_DIR = /home/dodo/Programming/algo-projects/algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/dodo/Programming/algo-projects/algorithms/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/karatsuba.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/karatsuba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/karatsuba.dir/flags.make

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o: CMakeFiles/karatsuba.dir/flags.make
CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o: ../math/karatsuba.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/dodo/Programming/algo-projects/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o"
	/usr/bin/clang++-5.0  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o -c /home/dodo/Programming/algo-projects/algorithms/math/karatsuba.cpp

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/karatsuba.dir/math/karatsuba.cpp.i"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/dodo/Programming/algo-projects/algorithms/math/karatsuba.cpp > CMakeFiles/karatsuba.dir/math/karatsuba.cpp.i

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/karatsuba.dir/math/karatsuba.cpp.s"
	/usr/bin/clang++-5.0 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/dodo/Programming/algo-projects/algorithms/math/karatsuba.cpp -o CMakeFiles/karatsuba.dir/math/karatsuba.cpp.s

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.requires:

.PHONY : CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.requires

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.provides: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.requires
	$(MAKE) -f CMakeFiles/karatsuba.dir/build.make CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.provides.build
.PHONY : CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.provides

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.provides.build: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o


# Object files for target karatsuba
karatsuba_OBJECTS = \
"CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o"

# External object files for target karatsuba
karatsuba_EXTERNAL_OBJECTS =

karatsuba: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o
karatsuba: CMakeFiles/karatsuba.dir/build.make
karatsuba: CMakeFiles/karatsuba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/dodo/Programming/algo-projects/algorithms/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable karatsuba"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/karatsuba.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/karatsuba.dir/build: karatsuba

.PHONY : CMakeFiles/karatsuba.dir/build

CMakeFiles/karatsuba.dir/requires: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.o.requires

.PHONY : CMakeFiles/karatsuba.dir/requires

CMakeFiles/karatsuba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/karatsuba.dir/cmake_clean.cmake
.PHONY : CMakeFiles/karatsuba.dir/clean

CMakeFiles/karatsuba.dir/depend:
	cd /home/dodo/Programming/algo-projects/algorithms/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/dodo/Programming/algo-projects/algorithms /home/dodo/Programming/algo-projects/algorithms /home/dodo/Programming/algo-projects/algorithms/cmake-build-debug /home/dodo/Programming/algo-projects/algorithms/cmake-build-debug /home/dodo/Programming/algo-projects/algorithms/cmake-build-debug/CMakeFiles/karatsuba.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/karatsuba.dir/depend

