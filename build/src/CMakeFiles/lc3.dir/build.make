# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_SOURCE_DIR = /home/adupree/lc3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adupree/lc3/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lc3.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lc3.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lc3.dir/flags.make

src/CMakeFiles/lc3.dir/lc3.c.o: src/CMakeFiles/lc3.dir/flags.make
src/CMakeFiles/lc3.dir/lc3.c.o: ../src/lc3.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adupree/lc3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/CMakeFiles/lc3.dir/lc3.c.o"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc3.dir/lc3.c.o   -c /home/adupree/lc3/src/lc3.c

src/CMakeFiles/lc3.dir/lc3.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc3.dir/lc3.c.i"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adupree/lc3/src/lc3.c > CMakeFiles/lc3.dir/lc3.c.i

src/CMakeFiles/lc3.dir/lc3.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc3.dir/lc3.c.s"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adupree/lc3/src/lc3.c -o CMakeFiles/lc3.dir/lc3.c.s

src/CMakeFiles/lc3.dir/trap.c.o: src/CMakeFiles/lc3.dir/flags.make
src/CMakeFiles/lc3.dir/trap.c.o: ../src/trap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adupree/lc3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/CMakeFiles/lc3.dir/trap.c.o"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc3.dir/trap.c.o   -c /home/adupree/lc3/src/trap.c

src/CMakeFiles/lc3.dir/trap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc3.dir/trap.c.i"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adupree/lc3/src/trap.c > CMakeFiles/lc3.dir/trap.c.i

src/CMakeFiles/lc3.dir/trap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc3.dir/trap.c.s"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adupree/lc3/src/trap.c -o CMakeFiles/lc3.dir/trap.c.s

src/CMakeFiles/lc3.dir/image.c.o: src/CMakeFiles/lc3.dir/flags.make
src/CMakeFiles/lc3.dir/image.c.o: ../src/image.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adupree/lc3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/CMakeFiles/lc3.dir/image.c.o"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc3.dir/image.c.o   -c /home/adupree/lc3/src/image.c

src/CMakeFiles/lc3.dir/image.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc3.dir/image.c.i"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adupree/lc3/src/image.c > CMakeFiles/lc3.dir/image.c.i

src/CMakeFiles/lc3.dir/image.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc3.dir/image.c.s"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adupree/lc3/src/image.c -o CMakeFiles/lc3.dir/image.c.s

src/CMakeFiles/lc3.dir/console.c.o: src/CMakeFiles/lc3.dir/flags.make
src/CMakeFiles/lc3.dir/console.c.o: ../src/console.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adupree/lc3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object src/CMakeFiles/lc3.dir/console.c.o"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lc3.dir/console.c.o   -c /home/adupree/lc3/src/console.c

src/CMakeFiles/lc3.dir/console.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lc3.dir/console.c.i"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adupree/lc3/src/console.c > CMakeFiles/lc3.dir/console.c.i

src/CMakeFiles/lc3.dir/console.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lc3.dir/console.c.s"
	cd /home/adupree/lc3/build/src && /bin/gcc-9 $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adupree/lc3/src/console.c -o CMakeFiles/lc3.dir/console.c.s

# Object files for target lc3
lc3_OBJECTS = \
"CMakeFiles/lc3.dir/lc3.c.o" \
"CMakeFiles/lc3.dir/trap.c.o" \
"CMakeFiles/lc3.dir/image.c.o" \
"CMakeFiles/lc3.dir/console.c.o"

# External object files for target lc3
lc3_EXTERNAL_OBJECTS =

src/lc3: src/CMakeFiles/lc3.dir/lc3.c.o
src/lc3: src/CMakeFiles/lc3.dir/trap.c.o
src/lc3: src/CMakeFiles/lc3.dir/image.c.o
src/lc3: src/CMakeFiles/lc3.dir/console.c.o
src/lc3: src/CMakeFiles/lc3.dir/build.make
src/lc3: src/CMakeFiles/lc3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adupree/lc3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable lc3"
	cd /home/adupree/lc3/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lc3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lc3.dir/build: src/lc3

.PHONY : src/CMakeFiles/lc3.dir/build

src/CMakeFiles/lc3.dir/clean:
	cd /home/adupree/lc3/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lc3.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lc3.dir/clean

src/CMakeFiles/lc3.dir/depend:
	cd /home/adupree/lc3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adupree/lc3 /home/adupree/lc3/src /home/adupree/lc3/build /home/adupree/lc3/build/src /home/adupree/lc3/build/src/CMakeFiles/lc3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lc3.dir/depend

