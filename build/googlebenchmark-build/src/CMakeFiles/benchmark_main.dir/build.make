# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/luis/repos/Compilers/CompilersProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/luis/repos/Compilers/CompilersProject/build

# Include any dependencies generated for this target.
include googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/depend.make

# Include the progress variables for this target.
include googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/progress.make

# Include the compile flags for this target's objects.
include googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/flags.make

googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/flags.make
googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: googlebenchmark-src/src/benchmark_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/luis/repos/Compilers/CompilersProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.o -c /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-src/src/benchmark_main.cc

googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_main.dir/benchmark_main.cc.i"
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-src/src/benchmark_main.cc > CMakeFiles/benchmark_main.dir/benchmark_main.cc.i

googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_main.dir/benchmark_main.cc.s"
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-src/src/benchmark_main.cc -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.s

# Object files for target benchmark_main
benchmark_main_OBJECTS = \
"CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"

# External object files for target benchmark_main
benchmark_main_EXTERNAL_OBJECTS =

googlebenchmark-build/src/libbenchmark_main.a: googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o
googlebenchmark-build/src/libbenchmark_main.a: googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/build.make
googlebenchmark-build/src/libbenchmark_main.a: googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/luis/repos/Compilers/CompilersProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbenchmark_main.a"
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean_target.cmake
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/build: googlebenchmark-build/src/libbenchmark_main.a

.PHONY : googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/build

googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/clean:
	cd /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean.cmake
.PHONY : googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/clean

googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/depend:
	cd /home/luis/repos/Compilers/CompilersProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/luis/repos/Compilers/CompilersProject /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-src/src /home/luis/repos/Compilers/CompilersProject/build /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src /home/luis/repos/Compilers/CompilersProject/build/googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : googlebenchmark-build/src/CMakeFiles/benchmark_main.dir/depend

