# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michael/Documents/Tutoring/DanielN/warboats

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michael/Documents/Tutoring/DanielN/warboats/build

# Include any dependencies generated for this target.
include CMakeFiles/w-big.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/w-big.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/w-big.dir/flags.make

CMakeFiles/w-big.dir/driver-big.cpp.o: CMakeFiles/w-big.dir/flags.make
CMakeFiles/w-big.dir/driver-big.cpp.o: ../driver-big.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/Tutoring/DanielN/warboats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/w-big.dir/driver-big.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/w-big.dir/driver-big.cpp.o -c /home/michael/Documents/Tutoring/DanielN/warboats/driver-big.cpp

CMakeFiles/w-big.dir/driver-big.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w-big.dir/driver-big.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/Tutoring/DanielN/warboats/driver-big.cpp > CMakeFiles/w-big.dir/driver-big.cpp.i

CMakeFiles/w-big.dir/driver-big.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w-big.dir/driver-big.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/Tutoring/DanielN/warboats/driver-big.cpp -o CMakeFiles/w-big.dir/driver-big.cpp.s

CMakeFiles/w-big.dir/Ocean.cpp.o: CMakeFiles/w-big.dir/flags.make
CMakeFiles/w-big.dir/Ocean.cpp.o: ../Ocean.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/Tutoring/DanielN/warboats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/w-big.dir/Ocean.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/w-big.dir/Ocean.cpp.o -c /home/michael/Documents/Tutoring/DanielN/warboats/Ocean.cpp

CMakeFiles/w-big.dir/Ocean.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w-big.dir/Ocean.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/Tutoring/DanielN/warboats/Ocean.cpp > CMakeFiles/w-big.dir/Ocean.cpp.i

CMakeFiles/w-big.dir/Ocean.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w-big.dir/Ocean.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/Tutoring/DanielN/warboats/Ocean.cpp -o CMakeFiles/w-big.dir/Ocean.cpp.s

CMakeFiles/w-big.dir/PRNG.cpp.o: CMakeFiles/w-big.dir/flags.make
CMakeFiles/w-big.dir/PRNG.cpp.o: ../PRNG.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michael/Documents/Tutoring/DanielN/warboats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/w-big.dir/PRNG.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/w-big.dir/PRNG.cpp.o -c /home/michael/Documents/Tutoring/DanielN/warboats/PRNG.cpp

CMakeFiles/w-big.dir/PRNG.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/w-big.dir/PRNG.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michael/Documents/Tutoring/DanielN/warboats/PRNG.cpp > CMakeFiles/w-big.dir/PRNG.cpp.i

CMakeFiles/w-big.dir/PRNG.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/w-big.dir/PRNG.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michael/Documents/Tutoring/DanielN/warboats/PRNG.cpp -o CMakeFiles/w-big.dir/PRNG.cpp.s

# Object files for target w-big
w__big_OBJECTS = \
"CMakeFiles/w-big.dir/driver-big.cpp.o" \
"CMakeFiles/w-big.dir/Ocean.cpp.o" \
"CMakeFiles/w-big.dir/PRNG.cpp.o"

# External object files for target w-big
w__big_EXTERNAL_OBJECTS =

w-big: CMakeFiles/w-big.dir/driver-big.cpp.o
w-big: CMakeFiles/w-big.dir/Ocean.cpp.o
w-big: CMakeFiles/w-big.dir/PRNG.cpp.o
w-big: CMakeFiles/w-big.dir/build.make
w-big: CMakeFiles/w-big.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michael/Documents/Tutoring/DanielN/warboats/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable w-big"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/w-big.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/w-big.dir/build: w-big

.PHONY : CMakeFiles/w-big.dir/build

CMakeFiles/w-big.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/w-big.dir/cmake_clean.cmake
.PHONY : CMakeFiles/w-big.dir/clean

CMakeFiles/w-big.dir/depend:
	cd /home/michael/Documents/Tutoring/DanielN/warboats/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michael/Documents/Tutoring/DanielN/warboats /home/michael/Documents/Tutoring/DanielN/warboats /home/michael/Documents/Tutoring/DanielN/warboats/build /home/michael/Documents/Tutoring/DanielN/warboats/build /home/michael/Documents/Tutoring/DanielN/warboats/build/CMakeFiles/w-big.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/w-big.dir/depend

