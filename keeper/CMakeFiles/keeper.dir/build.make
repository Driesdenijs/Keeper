# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = /home/pi/keeper/keeper

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/keeper/keeper

# Include any dependencies generated for this target.
include CMakeFiles/keeper.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/keeper.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/keeper.dir/flags.make

CMakeFiles/keeper.dir/src/door.c.o: CMakeFiles/keeper.dir/flags.make
CMakeFiles/keeper.dir/src/door.c.o: src/door.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/keeper/keeper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/keeper.dir/src/door.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/keeper.dir/src/door.c.o   -c /home/pi/keeper/keeper/src/door.c

CMakeFiles/keeper.dir/src/door.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/keeper.dir/src/door.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/keeper/keeper/src/door.c > CMakeFiles/keeper.dir/src/door.c.i

CMakeFiles/keeper.dir/src/door.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/keeper.dir/src/door.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/keeper/keeper/src/door.c -o CMakeFiles/keeper.dir/src/door.c.s

CMakeFiles/keeper.dir/src/door.c.o.requires:

.PHONY : CMakeFiles/keeper.dir/src/door.c.o.requires

CMakeFiles/keeper.dir/src/door.c.o.provides: CMakeFiles/keeper.dir/src/door.c.o.requires
	$(MAKE) -f CMakeFiles/keeper.dir/build.make CMakeFiles/keeper.dir/src/door.c.o.provides.build
.PHONY : CMakeFiles/keeper.dir/src/door.c.o.provides

CMakeFiles/keeper.dir/src/door.c.o.provides.build: CMakeFiles/keeper.dir/src/door.c.o


CMakeFiles/keeper.dir/src/keyfile.c.o: CMakeFiles/keeper.dir/flags.make
CMakeFiles/keeper.dir/src/keyfile.c.o: src/keyfile.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/keeper/keeper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/keeper.dir/src/keyfile.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/keeper.dir/src/keyfile.c.o   -c /home/pi/keeper/keeper/src/keyfile.c

CMakeFiles/keeper.dir/src/keyfile.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/keeper.dir/src/keyfile.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/keeper/keeper/src/keyfile.c > CMakeFiles/keeper.dir/src/keyfile.c.i

CMakeFiles/keeper.dir/src/keyfile.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/keeper.dir/src/keyfile.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/keeper/keeper/src/keyfile.c -o CMakeFiles/keeper.dir/src/keyfile.c.s

CMakeFiles/keeper.dir/src/keyfile.c.o.requires:

.PHONY : CMakeFiles/keeper.dir/src/keyfile.c.o.requires

CMakeFiles/keeper.dir/src/keyfile.c.o.provides: CMakeFiles/keeper.dir/src/keyfile.c.o.requires
	$(MAKE) -f CMakeFiles/keeper.dir/build.make CMakeFiles/keeper.dir/src/keyfile.c.o.provides.build
.PHONY : CMakeFiles/keeper.dir/src/keyfile.c.o.provides

CMakeFiles/keeper.dir/src/keyfile.c.o.provides.build: CMakeFiles/keeper.dir/src/keyfile.c.o


CMakeFiles/keeper.dir/src/main.c.o: CMakeFiles/keeper.dir/flags.make
CMakeFiles/keeper.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/keeper/keeper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/keeper.dir/src/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/keeper.dir/src/main.c.o   -c /home/pi/keeper/keeper/src/main.c

CMakeFiles/keeper.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/keeper.dir/src/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/keeper/keeper/src/main.c > CMakeFiles/keeper.dir/src/main.c.i

CMakeFiles/keeper.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/keeper.dir/src/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/keeper/keeper/src/main.c -o CMakeFiles/keeper.dir/src/main.c.s

CMakeFiles/keeper.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/keeper.dir/src/main.c.o.requires

CMakeFiles/keeper.dir/src/main.c.o.provides: CMakeFiles/keeper.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/keeper.dir/build.make CMakeFiles/keeper.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/keeper.dir/src/main.c.o.provides

CMakeFiles/keeper.dir/src/main.c.o.provides.build: CMakeFiles/keeper.dir/src/main.c.o


CMakeFiles/keeper.dir/src/reader.c.o: CMakeFiles/keeper.dir/flags.make
CMakeFiles/keeper.dir/src/reader.c.o: src/reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/keeper/keeper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/keeper.dir/src/reader.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/keeper.dir/src/reader.c.o   -c /home/pi/keeper/keeper/src/reader.c

CMakeFiles/keeper.dir/src/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/keeper.dir/src/reader.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/keeper/keeper/src/reader.c > CMakeFiles/keeper.dir/src/reader.c.i

CMakeFiles/keeper.dir/src/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/keeper.dir/src/reader.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/keeper/keeper/src/reader.c -o CMakeFiles/keeper.dir/src/reader.c.s

CMakeFiles/keeper.dir/src/reader.c.o.requires:

.PHONY : CMakeFiles/keeper.dir/src/reader.c.o.requires

CMakeFiles/keeper.dir/src/reader.c.o.provides: CMakeFiles/keeper.dir/src/reader.c.o.requires
	$(MAKE) -f CMakeFiles/keeper.dir/build.make CMakeFiles/keeper.dir/src/reader.c.o.provides.build
.PHONY : CMakeFiles/keeper.dir/src/reader.c.o.provides

CMakeFiles/keeper.dir/src/reader.c.o.provides.build: CMakeFiles/keeper.dir/src/reader.c.o


# Object files for target keeper
keeper_OBJECTS = \
"CMakeFiles/keeper.dir/src/door.c.o" \
"CMakeFiles/keeper.dir/src/keyfile.c.o" \
"CMakeFiles/keeper.dir/src/main.c.o" \
"CMakeFiles/keeper.dir/src/reader.c.o"

# External object files for target keeper
keeper_EXTERNAL_OBJECTS =

keeper: CMakeFiles/keeper.dir/src/door.c.o
keeper: CMakeFiles/keeper.dir/src/keyfile.c.o
keeper: CMakeFiles/keeper.dir/src/main.c.o
keeper: CMakeFiles/keeper.dir/src/reader.c.o
keeper: CMakeFiles/keeper.dir/build.make
keeper: CMakeFiles/keeper.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/keeper/keeper/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable keeper"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/keeper.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/keeper.dir/build: keeper

.PHONY : CMakeFiles/keeper.dir/build

CMakeFiles/keeper.dir/requires: CMakeFiles/keeper.dir/src/door.c.o.requires
CMakeFiles/keeper.dir/requires: CMakeFiles/keeper.dir/src/keyfile.c.o.requires
CMakeFiles/keeper.dir/requires: CMakeFiles/keeper.dir/src/main.c.o.requires
CMakeFiles/keeper.dir/requires: CMakeFiles/keeper.dir/src/reader.c.o.requires

.PHONY : CMakeFiles/keeper.dir/requires

CMakeFiles/keeper.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/keeper.dir/cmake_clean.cmake
.PHONY : CMakeFiles/keeper.dir/clean

CMakeFiles/keeper.dir/depend:
	cd /home/pi/keeper/keeper && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/keeper/keeper /home/pi/keeper/keeper /home/pi/keeper/keeper /home/pi/keeper/keeper /home/pi/keeper/keeper/CMakeFiles/keeper.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/keeper.dir/depend
