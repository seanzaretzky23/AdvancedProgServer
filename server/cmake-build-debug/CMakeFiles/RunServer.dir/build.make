# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /opt/clion-2017.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /opt/clion-2017.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sean/Desktop/ex4/src/server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sean/Desktop/ex4/src/server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RunServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RunServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RunServer.dir/flags.make

CMakeFiles/RunServer.dir/mainServer.cpp.o: CMakeFiles/RunServer.dir/flags.make
CMakeFiles/RunServer.dir/mainServer.cpp.o: ../mainServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Desktop/ex4/src/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RunServer.dir/mainServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RunServer.dir/mainServer.cpp.o -c /home/sean/Desktop/ex4/src/server/mainServer.cpp

CMakeFiles/RunServer.dir/mainServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunServer.dir/mainServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Desktop/ex4/src/server/mainServer.cpp > CMakeFiles/RunServer.dir/mainServer.cpp.i

CMakeFiles/RunServer.dir/mainServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunServer.dir/mainServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Desktop/ex4/src/server/mainServer.cpp -o CMakeFiles/RunServer.dir/mainServer.cpp.s

CMakeFiles/RunServer.dir/mainServer.cpp.o.requires:

.PHONY : CMakeFiles/RunServer.dir/mainServer.cpp.o.requires

CMakeFiles/RunServer.dir/mainServer.cpp.o.provides: CMakeFiles/RunServer.dir/mainServer.cpp.o.requires
	$(MAKE) -f CMakeFiles/RunServer.dir/build.make CMakeFiles/RunServer.dir/mainServer.cpp.o.provides.build
.PHONY : CMakeFiles/RunServer.dir/mainServer.cpp.o.provides

CMakeFiles/RunServer.dir/mainServer.cpp.o.provides.build: CMakeFiles/RunServer.dir/mainServer.cpp.o


CMakeFiles/RunServer.dir/Server.cpp.o: CMakeFiles/RunServer.dir/flags.make
CMakeFiles/RunServer.dir/Server.cpp.o: ../Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Desktop/ex4/src/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RunServer.dir/Server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RunServer.dir/Server.cpp.o -c /home/sean/Desktop/ex4/src/server/Server.cpp

CMakeFiles/RunServer.dir/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunServer.dir/Server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Desktop/ex4/src/server/Server.cpp > CMakeFiles/RunServer.dir/Server.cpp.i

CMakeFiles/RunServer.dir/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunServer.dir/Server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Desktop/ex4/src/server/Server.cpp -o CMakeFiles/RunServer.dir/Server.cpp.s

CMakeFiles/RunServer.dir/Server.cpp.o.requires:

.PHONY : CMakeFiles/RunServer.dir/Server.cpp.o.requires

CMakeFiles/RunServer.dir/Server.cpp.o.provides: CMakeFiles/RunServer.dir/Server.cpp.o.requires
	$(MAKE) -f CMakeFiles/RunServer.dir/build.make CMakeFiles/RunServer.dir/Server.cpp.o.provides.build
.PHONY : CMakeFiles/RunServer.dir/Server.cpp.o.provides

CMakeFiles/RunServer.dir/Server.cpp.o.provides.build: CMakeFiles/RunServer.dir/Server.cpp.o


CMakeFiles/RunServer.dir/ReadFile.cpp.o: CMakeFiles/RunServer.dir/flags.make
CMakeFiles/RunServer.dir/ReadFile.cpp.o: ../ReadFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sean/Desktop/ex4/src/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RunServer.dir/ReadFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RunServer.dir/ReadFile.cpp.o -c /home/sean/Desktop/ex4/src/server/ReadFile.cpp

CMakeFiles/RunServer.dir/ReadFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RunServer.dir/ReadFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sean/Desktop/ex4/src/server/ReadFile.cpp > CMakeFiles/RunServer.dir/ReadFile.cpp.i

CMakeFiles/RunServer.dir/ReadFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RunServer.dir/ReadFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sean/Desktop/ex4/src/server/ReadFile.cpp -o CMakeFiles/RunServer.dir/ReadFile.cpp.s

CMakeFiles/RunServer.dir/ReadFile.cpp.o.requires:

.PHONY : CMakeFiles/RunServer.dir/ReadFile.cpp.o.requires

CMakeFiles/RunServer.dir/ReadFile.cpp.o.provides: CMakeFiles/RunServer.dir/ReadFile.cpp.o.requires
	$(MAKE) -f CMakeFiles/RunServer.dir/build.make CMakeFiles/RunServer.dir/ReadFile.cpp.o.provides.build
.PHONY : CMakeFiles/RunServer.dir/ReadFile.cpp.o.provides

CMakeFiles/RunServer.dir/ReadFile.cpp.o.provides.build: CMakeFiles/RunServer.dir/ReadFile.cpp.o


# Object files for target RunServer
RunServer_OBJECTS = \
"CMakeFiles/RunServer.dir/mainServer.cpp.o" \
"CMakeFiles/RunServer.dir/Server.cpp.o" \
"CMakeFiles/RunServer.dir/ReadFile.cpp.o"

# External object files for target RunServer
RunServer_EXTERNAL_OBJECTS =

RunServer: CMakeFiles/RunServer.dir/mainServer.cpp.o
RunServer: CMakeFiles/RunServer.dir/Server.cpp.o
RunServer: CMakeFiles/RunServer.dir/ReadFile.cpp.o
RunServer: CMakeFiles/RunServer.dir/build.make
RunServer: CMakeFiles/RunServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sean/Desktop/ex4/src/server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RunServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RunServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RunServer.dir/build: RunServer

.PHONY : CMakeFiles/RunServer.dir/build

CMakeFiles/RunServer.dir/requires: CMakeFiles/RunServer.dir/mainServer.cpp.o.requires
CMakeFiles/RunServer.dir/requires: CMakeFiles/RunServer.dir/Server.cpp.o.requires
CMakeFiles/RunServer.dir/requires: CMakeFiles/RunServer.dir/ReadFile.cpp.o.requires

.PHONY : CMakeFiles/RunServer.dir/requires

CMakeFiles/RunServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RunServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RunServer.dir/clean

CMakeFiles/RunServer.dir/depend:
	cd /home/sean/Desktop/ex4/src/server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sean/Desktop/ex4/src/server /home/sean/Desktop/ex4/src/server /home/sean/Desktop/ex4/src/server/cmake-build-debug /home/sean/Desktop/ex4/src/server/cmake-build-debug /home/sean/Desktop/ex4/src/server/cmake-build-debug/CMakeFiles/RunServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RunServer.dir/depend
