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
CMAKE_COMMAND = /dls_sw/prod/tools/RHEL7-x86_64/clion/2019-2/src/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /dls_sw/prod/tools/RHEL7-x86_64/clion/2019-2/src/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/castOperators.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/castOperators.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/castOperators.dir/flags.make

CMakeFiles/castOperators.dir/main.cpp.o: CMakeFiles/castOperators.dir/flags.make
CMakeFiles/castOperators.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/castOperators.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/castOperators.dir/main.cpp.o -c /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/main.cpp

CMakeFiles/castOperators.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/castOperators.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/main.cpp > CMakeFiles/castOperators.dir/main.cpp.i

CMakeFiles/castOperators.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/castOperators.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/main.cpp -o CMakeFiles/castOperators.dir/main.cpp.s

CMakeFiles/castOperators.dir/Time.cpp.o: CMakeFiles/castOperators.dir/flags.make
CMakeFiles/castOperators.dir/Time.cpp.o: ../Time.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/castOperators.dir/Time.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/castOperators.dir/Time.cpp.o -c /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/Time.cpp

CMakeFiles/castOperators.dir/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/castOperators.dir/Time.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/Time.cpp > CMakeFiles/castOperators.dir/Time.cpp.i

CMakeFiles/castOperators.dir/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/castOperators.dir/Time.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/Time.cpp -o CMakeFiles/castOperators.dir/Time.cpp.s

# Object files for target castOperators
castOperators_OBJECTS = \
"CMakeFiles/castOperators.dir/main.cpp.o" \
"CMakeFiles/castOperators.dir/Time.cpp.o"

# External object files for target castOperators
castOperators_EXTERNAL_OBJECTS =

castOperators: CMakeFiles/castOperators.dir/main.cpp.o
castOperators: CMakeFiles/castOperators.dir/Time.cpp.o
castOperators: CMakeFiles/castOperators.dir/build.make
castOperators: CMakeFiles/castOperators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable castOperators"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/castOperators.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/castOperators.dir/build: castOperators

.PHONY : CMakeFiles/castOperators.dir/build

CMakeFiles/castOperators.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/castOperators.dir/cmake_clean.cmake
.PHONY : CMakeFiles/castOperators.dir/clean

CMakeFiles/castOperators.dir/depend:
	cd /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug /home/jjc62351/ProgrammingCourses/cppAdvanced/castOperators/cmake-build-debug/CMakeFiles/castOperators.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/castOperators.dir/depend

