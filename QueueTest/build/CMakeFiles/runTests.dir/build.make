# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/d/BOSCH/QueueTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/d/BOSCH/QueueTest/build

# Include any dependencies generated for this target.
include CMakeFiles/runTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTests.dir/flags.make

CMakeFiles/runTests.dir/test_queue.cpp.o: CMakeFiles/runTests.dir/flags.make
CMakeFiles/runTests.dir/test_queue.cpp.o: ../test_queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/d/BOSCH/QueueTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTests.dir/test_queue.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTests.dir/test_queue.cpp.o -c /cygdrive/d/BOSCH/QueueTest/test_queue.cpp

CMakeFiles/runTests.dir/test_queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/test_queue.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/d/BOSCH/QueueTest/test_queue.cpp > CMakeFiles/runTests.dir/test_queue.cpp.i

CMakeFiles/runTests.dir/test_queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/test_queue.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/d/BOSCH/QueueTest/test_queue.cpp -o CMakeFiles/runTests.dir/test_queue.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/test_queue.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

runTests.exe: CMakeFiles/runTests.dir/test_queue.cpp.o
runTests.exe: CMakeFiles/runTests.dir/build.make
runTests.exe: CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/d/BOSCH/QueueTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTests.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTests.dir/build: runTests.exe

.PHONY : CMakeFiles/runTests.dir/build

CMakeFiles/runTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTests.dir/clean

CMakeFiles/runTests.dir/depend:
	cd /cygdrive/d/BOSCH/QueueTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/d/BOSCH/QueueTest /cygdrive/d/BOSCH/QueueTest /cygdrive/d/BOSCH/QueueTest/build /cygdrive/d/BOSCH/QueueTest/build /cygdrive/d/BOSCH/QueueTest/build/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTests.dir/depend

