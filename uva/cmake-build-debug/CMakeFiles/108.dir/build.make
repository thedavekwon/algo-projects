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
CMAKE_SOURCE_DIR = C:\Users\Administrator\CLionProjects\algo-projects\uva

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/108.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/108.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/108.dir/flags.make

CMakeFiles/108.dir/108/108.cpp.obj: CMakeFiles/108.dir/flags.make
CMakeFiles/108.dir/108/108.cpp.obj: ../108/108.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/108.dir/108/108.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\108.dir\108\108.cpp.obj -c C:\Users\Administrator\CLionProjects\algo-projects\uva\108\108.cpp

CMakeFiles/108.dir/108/108.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/108.dir/108/108.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\CLionProjects\algo-projects\uva\108\108.cpp > CMakeFiles\108.dir\108\108.cpp.i

CMakeFiles/108.dir/108/108.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/108.dir/108/108.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\CLionProjects\algo-projects\uva\108\108.cpp -o CMakeFiles\108.dir\108\108.cpp.s

CMakeFiles/108.dir/108/108.cpp.obj.requires:

.PHONY : CMakeFiles/108.dir/108/108.cpp.obj.requires

CMakeFiles/108.dir/108/108.cpp.obj.provides: CMakeFiles/108.dir/108/108.cpp.obj.requires
	$(MAKE) -f CMakeFiles\108.dir\build.make CMakeFiles/108.dir/108/108.cpp.obj.provides.build
.PHONY : CMakeFiles/108.dir/108/108.cpp.obj.provides

CMakeFiles/108.dir/108/108.cpp.obj.provides.build: CMakeFiles/108.dir/108/108.cpp.obj


# Object files for target 108
108_OBJECTS = \
"CMakeFiles/108.dir/108/108.cpp.obj"

# External object files for target 108
108_EXTERNAL_OBJECTS =

108.exe: CMakeFiles/108.dir/108/108.cpp.obj
108.exe: CMakeFiles/108.dir/build.make
108.exe: CMakeFiles/108.dir/linklibs.rsp
108.exe: CMakeFiles/108.dir/objects1.rsp
108.exe: CMakeFiles/108.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 108.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\108.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/108.dir/build: 108.exe

.PHONY : CMakeFiles/108.dir/build

CMakeFiles/108.dir/requires: CMakeFiles/108.dir/108/108.cpp.obj.requires

.PHONY : CMakeFiles/108.dir/requires

CMakeFiles/108.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\108.dir\cmake_clean.cmake
.PHONY : CMakeFiles/108.dir/clean

CMakeFiles/108.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\CLionProjects\algo-projects\uva C:\Users\Administrator\CLionProjects\algo-projects\uva C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles\108.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/108.dir/depend

