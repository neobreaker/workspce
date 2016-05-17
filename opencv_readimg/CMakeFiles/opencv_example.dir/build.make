# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/neo/workspce/opencv_readimg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/neo/workspce/opencv_readimg

# Include any dependencies generated for this target.
include CMakeFiles/opencv_example.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_example.dir/flags.make

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o: CMakeFiles/opencv_example.dir/flags.make
CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o: opencv_readimg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/neo/workspce/opencv_readimg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o -c /home/neo/workspce/opencv_readimg/opencv_readimg.cpp

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_example.dir/opencv_readimg.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/neo/workspce/opencv_readimg/opencv_readimg.cpp > CMakeFiles/opencv_example.dir/opencv_readimg.cpp.i

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_example.dir/opencv_readimg.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/neo/workspce/opencv_readimg/opencv_readimg.cpp -o CMakeFiles/opencv_example.dir/opencv_readimg.cpp.s

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.requires:

.PHONY : CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.requires

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.provides: CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.requires
	$(MAKE) -f CMakeFiles/opencv_example.dir/build.make CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.provides.build
.PHONY : CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.provides

CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.provides.build: CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o


# Object files for target opencv_example
opencv_example_OBJECTS = \
"CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o"

# External object files for target opencv_example
opencv_example_EXTERNAL_OBJECTS =

opencv_example: CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o
opencv_example: CMakeFiles/opencv_example.dir/build.make
opencv_example: /usr/local/lib/libopencv_videostab.so.3.1.0
opencv_example: /usr/local/lib/libopencv_superres.so.3.1.0
opencv_example: /usr/local/lib/libopencv_stitching.so.3.1.0
opencv_example: /usr/local/lib/libopencv_shape.so.3.1.0
opencv_example: /usr/local/lib/libopencv_photo.so.3.1.0
opencv_example: /usr/local/lib/libopencv_objdetect.so.3.1.0
opencv_example: /usr/local/lib/libopencv_calib3d.so.3.1.0
opencv_example: /usr/local/lib/libopencv_features2d.so.3.1.0
opencv_example: /usr/local/lib/libopencv_ml.so.3.1.0
opencv_example: /usr/local/lib/libopencv_highgui.so.3.1.0
opencv_example: /usr/local/lib/libopencv_videoio.so.3.1.0
opencv_example: /usr/local/lib/libopencv_imgcodecs.so.3.1.0
opencv_example: /usr/local/lib/libopencv_flann.so.3.1.0
opencv_example: /usr/local/lib/libopencv_video.so.3.1.0
opencv_example: /usr/local/lib/libopencv_imgproc.so.3.1.0
opencv_example: /usr/local/lib/libopencv_core.so.3.1.0
opencv_example: CMakeFiles/opencv_example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/neo/workspce/opencv_readimg/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv_example"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_example.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_example.dir/build: opencv_example

.PHONY : CMakeFiles/opencv_example.dir/build

CMakeFiles/opencv_example.dir/requires: CMakeFiles/opencv_example.dir/opencv_readimg.cpp.o.requires

.PHONY : CMakeFiles/opencv_example.dir/requires

CMakeFiles/opencv_example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_example.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_example.dir/clean

CMakeFiles/opencv_example.dir/depend:
	cd /home/neo/workspce/opencv_readimg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/neo/workspce/opencv_readimg /home/neo/workspce/opencv_readimg /home/neo/workspce/opencv_readimg /home/neo/workspce/opencv_readimg /home/neo/workspce/opencv_readimg/CMakeFiles/opencv_example.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_example.dir/depend

