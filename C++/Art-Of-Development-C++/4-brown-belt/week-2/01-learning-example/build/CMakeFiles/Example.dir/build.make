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
CMAKE_SOURCE_DIR = /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build

# Include any dependencies generated for this target.
include CMakeFiles/Example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Example.dir/flags.make

CMakeFiles/Example.dir/01-learning-example.cpp.o: CMakeFiles/Example.dir/flags.make
CMakeFiles/Example.dir/01-learning-example.cpp.o: ../01-learning-example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Example.dir/01-learning-example.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Example.dir/01-learning-example.cpp.o -c /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/01-learning-example.cpp

CMakeFiles/Example.dir/01-learning-example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Example.dir/01-learning-example.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/01-learning-example.cpp > CMakeFiles/Example.dir/01-learning-example.cpp.i

CMakeFiles/Example.dir/01-learning-example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Example.dir/01-learning-example.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/01-learning-example.cpp -o CMakeFiles/Example.dir/01-learning-example.cpp.s

CMakeFiles/Example.dir/xml.cpp.o: CMakeFiles/Example.dir/flags.make
CMakeFiles/Example.dir/xml.cpp.o: ../xml.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Example.dir/xml.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Example.dir/xml.cpp.o -c /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/xml.cpp

CMakeFiles/Example.dir/xml.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Example.dir/xml.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/xml.cpp > CMakeFiles/Example.dir/xml.cpp.i

CMakeFiles/Example.dir/xml.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Example.dir/xml.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/xml.cpp -o CMakeFiles/Example.dir/xml.cpp.s

CMakeFiles/Example.dir/json.cpp.o: CMakeFiles/Example.dir/flags.make
CMakeFiles/Example.dir/json.cpp.o: ../json.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Example.dir/json.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Example.dir/json.cpp.o -c /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/json.cpp

CMakeFiles/Example.dir/json.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Example.dir/json.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/json.cpp > CMakeFiles/Example.dir/json.cpp.i

CMakeFiles/Example.dir/json.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Example.dir/json.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/json.cpp -o CMakeFiles/Example.dir/json.cpp.s

# Object files for target Example
Example_OBJECTS = \
"CMakeFiles/Example.dir/01-learning-example.cpp.o" \
"CMakeFiles/Example.dir/xml.cpp.o" \
"CMakeFiles/Example.dir/json.cpp.o"

# External object files for target Example
Example_EXTERNAL_OBJECTS =

Example: CMakeFiles/Example.dir/01-learning-example.cpp.o
Example: CMakeFiles/Example.dir/xml.cpp.o
Example: CMakeFiles/Example.dir/json.cpp.o
Example: CMakeFiles/Example.dir/build.make
Example: CMakeFiles/Example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Example.dir/build: Example

.PHONY : CMakeFiles/Example.dir/build

CMakeFiles/Example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Example.dir/clean

CMakeFiles/Example.dir/depend:
	cd /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2 /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2 /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build /home/person/Документы/__repo__/languages-playground/C++/Art-Of-Development-C++/4-brown-belt/week-2/build/CMakeFiles/Example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Example.dir/depend

