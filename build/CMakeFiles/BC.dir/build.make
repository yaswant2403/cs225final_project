# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspaces/cs225/cs225final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/cs225/cs225final_project/build

# Include any dependencies generated for this target.
include CMakeFiles/BC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BC.dir/flags.make

CMakeFiles/BC.dir/entry/BC.cpp.o: CMakeFiles/BC.dir/flags.make
CMakeFiles/BC.dir/entry/BC.cpp.o: ../entry/BC.cpp
CMakeFiles/BC.dir/entry/BC.cpp.o: CMakeFiles/BC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/cs225/cs225final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BC.dir/entry/BC.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BC.dir/entry/BC.cpp.o -MF CMakeFiles/BC.dir/entry/BC.cpp.o.d -o CMakeFiles/BC.dir/entry/BC.cpp.o -c /workspaces/cs225/cs225final_project/entry/BC.cpp

CMakeFiles/BC.dir/entry/BC.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BC.dir/entry/BC.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/cs225/cs225final_project/entry/BC.cpp > CMakeFiles/BC.dir/entry/BC.cpp.i

CMakeFiles/BC.dir/entry/BC.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BC.dir/entry/BC.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/cs225/cs225final_project/entry/BC.cpp -o CMakeFiles/BC.dir/entry/BC.cpp.s

# Object files for target BC
BC_OBJECTS = \
"CMakeFiles/BC.dir/entry/BC.cpp.o"

# External object files for target BC
BC_EXTERNAL_OBJECTS =

BC: CMakeFiles/BC.dir/entry/BC.cpp.o
BC: CMakeFiles/BC.dir/build.make
BC: src/libsrc.a
BC: CMakeFiles/BC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/cs225/cs225final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BC"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BC.dir/build: BC
.PHONY : CMakeFiles/BC.dir/build

CMakeFiles/BC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BC.dir/clean

CMakeFiles/BC.dir/depend:
	cd /workspaces/cs225/cs225final_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/cs225/cs225final_project /workspaces/cs225/cs225final_project /workspaces/cs225/cs225final_project/build /workspaces/cs225/cs225final_project/build /workspaces/cs225/cs225final_project/build/CMakeFiles/BC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BC.dir/depend

