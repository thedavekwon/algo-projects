# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.10

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.1.5\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\CLionProjects\algo-projects\algorithms

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/karatsuba.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/karatsuba.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/karatsuba.dir/flags.make

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj: CMakeFiles/karatsuba.dir/flags.make
CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj: ../math/karatsuba.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\karatsuba.dir\math\karatsuba.cpp.obj -c C:\Users\Administrator\CLionProjects\algo-projects\algorithms\math\karatsuba.cpp

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/karatsuba.dir/math/karatsuba.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\CLionProjects\algo-projects\algorithms\math\karatsuba.cpp > CMakeFiles\karatsuba.dir\math\karatsuba.cpp.i

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/karatsuba.dir/math/karatsuba.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\CLionProjects\algo-projects\algorithms\math\karatsuba.cpp -o CMakeFiles\karatsuba.dir\math\karatsuba.cpp.s

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.requires:

.PHONY : CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.requires

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.provides: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.requires
	$(MAKE) -f CMakeFiles\karatsuba.dir\build.make CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.provides.build
.PHONY : CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.provides

CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.provides.build: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj


# Object files for target karatsuba
karatsuba_OBJECTS = \
"CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj"

# External object files for target karatsuba
karatsuba_EXTERNAL_OBJECTS =

karatsuba.exe: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj
karatsuba.exe: CMakeFiles/karatsuba.dir/build.make
karatsuba.exe: CMakeFiles/karatsuba.dir/linklibs.rsp
karatsuba.exe: CMakeFiles/karatsuba.dir/objects1.rsp
karatsuba.exe: CMakeFiles/karatsuba.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable karatsuba.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\karatsuba.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/karatsuba.dir/build: karatsuba.exe

.PHONY : CMakeFiles/karatsuba.dir/build

CMakeFiles/karatsuba.dir/requires: CMakeFiles/karatsuba.dir/math/karatsuba.cpp.obj.requires

.PHONY : CMakeFiles/karatsuba.dir/requires

CMakeFiles/karatsuba.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\karatsuba.dir\cmake_clean.cmake
.PHONY : CMakeFiles/karatsuba.dir/clean

CMakeFiles/karatsuba.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\CLionProjects\algo-projects\algorithms C:\Users\Administrator\CLionProjects\algo-projects\algorithms C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\algorithms\cmake-build-debug\CMakeFiles\karatsuba.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/karatsuba.dir/depend

