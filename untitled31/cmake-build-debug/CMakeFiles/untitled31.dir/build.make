# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.1.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\25728\CLionProjects\untitled31

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\25728\CLionProjects\untitled31\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled31.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled31.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled31.dir/flags.make

CMakeFiles/untitled31.dir/main.cpp.obj: CMakeFiles/untitled31.dir/flags.make
CMakeFiles/untitled31.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\25728\CLionProjects\untitled31\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled31.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled31.dir\main.cpp.obj -c C:\Users\25728\CLionProjects\untitled31\main.cpp

CMakeFiles/untitled31.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled31.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\25728\CLionProjects\untitled31\main.cpp > CMakeFiles\untitled31.dir\main.cpp.i

CMakeFiles/untitled31.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled31.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\25728\CLionProjects\untitled31\main.cpp -o CMakeFiles\untitled31.dir\main.cpp.s

CMakeFiles/untitled31.dir/roomtype.cpp.obj: CMakeFiles/untitled31.dir/flags.make
CMakeFiles/untitled31.dir/roomtype.cpp.obj: ../roomtype.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\25728\CLionProjects\untitled31\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled31.dir/roomtype.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\untitled31.dir\roomtype.cpp.obj -c C:\Users\25728\CLionProjects\untitled31\roomtype.cpp

CMakeFiles/untitled31.dir/roomtype.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled31.dir/roomtype.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\25728\CLionProjects\untitled31\roomtype.cpp > CMakeFiles\untitled31.dir\roomtype.cpp.i

CMakeFiles/untitled31.dir/roomtype.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled31.dir/roomtype.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\25728\CLionProjects\untitled31\roomtype.cpp -o CMakeFiles\untitled31.dir\roomtype.cpp.s

# Object files for target untitled31
untitled31_OBJECTS = \
"CMakeFiles/untitled31.dir/main.cpp.obj" \
"CMakeFiles/untitled31.dir/roomtype.cpp.obj"

# External object files for target untitled31
untitled31_EXTERNAL_OBJECTS =

untitled31.exe: CMakeFiles/untitled31.dir/main.cpp.obj
untitled31.exe: CMakeFiles/untitled31.dir/roomtype.cpp.obj
untitled31.exe: CMakeFiles/untitled31.dir/build.make
untitled31.exe: CMakeFiles/untitled31.dir/linklibs.rsp
untitled31.exe: CMakeFiles/untitled31.dir/objects1.rsp
untitled31.exe: CMakeFiles/untitled31.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\25728\CLionProjects\untitled31\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable untitled31.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\untitled31.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled31.dir/build: untitled31.exe

.PHONY : CMakeFiles/untitled31.dir/build

CMakeFiles/untitled31.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\untitled31.dir\cmake_clean.cmake
.PHONY : CMakeFiles/untitled31.dir/clean

CMakeFiles/untitled31.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\25728\CLionProjects\untitled31 C:\Users\25728\CLionProjects\untitled31 C:\Users\25728\CLionProjects\untitled31\cmake-build-debug C:\Users\25728\CLionProjects\untitled31\cmake-build-debug C:\Users\25728\CLionProjects\untitled31\cmake-build-debug\CMakeFiles\untitled31.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled31.dir/depend

