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
include CMakeFiles/test1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test1.dir/flags.make

CMakeFiles/test1.dir/test1.c.obj: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/test1.c.obj: ../test1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test1.dir/test1.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test1.dir\test1.c.obj   -c C:\Users\Administrator\CLionProjects\algo-projects\uva\test1.c

CMakeFiles/test1.dir/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test1.dir/test1.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Administrator\CLionProjects\algo-projects\uva\test1.c > CMakeFiles\test1.dir\test1.c.i

CMakeFiles/test1.dir/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test1.dir/test1.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Administrator\CLionProjects\algo-projects\uva\test1.c -o CMakeFiles\test1.dir\test1.c.s

CMakeFiles/test1.dir/test1.c.obj.requires:

.PHONY : CMakeFiles/test1.dir/test1.c.obj.requires

CMakeFiles/test1.dir/test1.c.obj.provides: CMakeFiles/test1.dir/test1.c.obj.requires
	$(MAKE) -f CMakeFiles\test1.dir\build.make CMakeFiles/test1.dir/test1.c.obj.provides.build
.PHONY : CMakeFiles/test1.dir/test1.c.obj.provides

CMakeFiles/test1.dir/test1.c.obj.provides.build: CMakeFiles/test1.dir/test1.c.obj


# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/test1.c.obj"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

test1.exe: CMakeFiles/test1.dir/test1.c.obj
test1.exe: CMakeFiles/test1.dir/build.make
test1.exe: CMakeFiles/test1.dir/linklibs.rsp
test1.exe: CMakeFiles/test1.dir/objects1.rsp
test1.exe: CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test1.dir/build: test1.exe

.PHONY : CMakeFiles/test1.dir/build

CMakeFiles/test1.dir/requires: CMakeFiles/test1.dir/test1.c.obj.requires

.PHONY : CMakeFiles/test1.dir/requires

CMakeFiles/test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test1.dir/clean

CMakeFiles/test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\CLionProjects\algo-projects\uva C:\Users\Administrator\CLionProjects\algo-projects\uva C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug C:\Users\Administrator\CLionProjects\algo-projects\uva\cmake-build-debug\CMakeFiles\test1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test1.dir/depend

