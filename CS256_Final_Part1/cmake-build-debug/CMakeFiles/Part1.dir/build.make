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
CMAKE_COMMAND = /home/tlinkey/Programs/clion-2018.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/tlinkey/Programs/clion-2018.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Part1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Part1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Part1.dir/flags.make

CMakeFiles/Part1.dir/main.cpp.o: CMakeFiles/Part1.dir/flags.make
CMakeFiles/Part1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Part1.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part1.dir/main.cpp.o -c /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/main.cpp

CMakeFiles/Part1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part1.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/main.cpp > CMakeFiles/Part1.dir/main.cpp.i

CMakeFiles/Part1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part1.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/main.cpp -o CMakeFiles/Part1.dir/main.cpp.s

CMakeFiles/Part1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Part1.dir/main.cpp.o.requires

CMakeFiles/Part1.dir/main.cpp.o.provides: CMakeFiles/Part1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part1.dir/build.make CMakeFiles/Part1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Part1.dir/main.cpp.o.provides

CMakeFiles/Part1.dir/main.cpp.o.provides.build: CMakeFiles/Part1.dir/main.cpp.o


CMakeFiles/Part1.dir/BigNumbers.cpp.o: CMakeFiles/Part1.dir/flags.make
CMakeFiles/Part1.dir/BigNumbers.cpp.o: ../BigNumbers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Part1.dir/BigNumbers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part1.dir/BigNumbers.cpp.o -c /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/BigNumbers.cpp

CMakeFiles/Part1.dir/BigNumbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part1.dir/BigNumbers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/BigNumbers.cpp > CMakeFiles/Part1.dir/BigNumbers.cpp.i

CMakeFiles/Part1.dir/BigNumbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part1.dir/BigNumbers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/BigNumbers.cpp -o CMakeFiles/Part1.dir/BigNumbers.cpp.s

CMakeFiles/Part1.dir/BigNumbers.cpp.o.requires:

.PHONY : CMakeFiles/Part1.dir/BigNumbers.cpp.o.requires

CMakeFiles/Part1.dir/BigNumbers.cpp.o.provides: CMakeFiles/Part1.dir/BigNumbers.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part1.dir/build.make CMakeFiles/Part1.dir/BigNumbers.cpp.o.provides.build
.PHONY : CMakeFiles/Part1.dir/BigNumbers.cpp.o.provides

CMakeFiles/Part1.dir/BigNumbers.cpp.o.provides.build: CMakeFiles/Part1.dir/BigNumbers.cpp.o


CMakeFiles/Part1.dir/IO.cpp.o: CMakeFiles/Part1.dir/flags.make
CMakeFiles/Part1.dir/IO.cpp.o: ../IO.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Part1.dir/IO.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Part1.dir/IO.cpp.o -c /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/IO.cpp

CMakeFiles/Part1.dir/IO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Part1.dir/IO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/IO.cpp > CMakeFiles/Part1.dir/IO.cpp.i

CMakeFiles/Part1.dir/IO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Part1.dir/IO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/IO.cpp -o CMakeFiles/Part1.dir/IO.cpp.s

CMakeFiles/Part1.dir/IO.cpp.o.requires:

.PHONY : CMakeFiles/Part1.dir/IO.cpp.o.requires

CMakeFiles/Part1.dir/IO.cpp.o.provides: CMakeFiles/Part1.dir/IO.cpp.o.requires
	$(MAKE) -f CMakeFiles/Part1.dir/build.make CMakeFiles/Part1.dir/IO.cpp.o.provides.build
.PHONY : CMakeFiles/Part1.dir/IO.cpp.o.provides

CMakeFiles/Part1.dir/IO.cpp.o.provides.build: CMakeFiles/Part1.dir/IO.cpp.o


# Object files for target Part1
Part1_OBJECTS = \
"CMakeFiles/Part1.dir/main.cpp.o" \
"CMakeFiles/Part1.dir/BigNumbers.cpp.o" \
"CMakeFiles/Part1.dir/IO.cpp.o"

# External object files for target Part1
Part1_EXTERNAL_OBJECTS =

Part1: CMakeFiles/Part1.dir/main.cpp.o
Part1: CMakeFiles/Part1.dir/BigNumbers.cpp.o
Part1: CMakeFiles/Part1.dir/IO.cpp.o
Part1: CMakeFiles/Part1.dir/build.make
Part1: CMakeFiles/Part1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Part1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Part1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Part1.dir/build: Part1

.PHONY : CMakeFiles/Part1.dir/build

CMakeFiles/Part1.dir/requires: CMakeFiles/Part1.dir/main.cpp.o.requires
CMakeFiles/Part1.dir/requires: CMakeFiles/Part1.dir/BigNumbers.cpp.o.requires
CMakeFiles/Part1.dir/requires: CMakeFiles/Part1.dir/IO.cpp.o.requires

.PHONY : CMakeFiles/Part1.dir/requires

CMakeFiles/Part1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Part1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Part1.dir/clean

CMakeFiles/Part1.dir/depend:
	cd /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1 /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1 /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug /home/tlinkey/Projects/School/CS256/Workspace/Final/Part1/cmake-build-debug/CMakeFiles/Part1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Part1.dir/depend

