# Copyright © 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

project(BRSS)
cmake_minimum_required(VERSION 3.0.2)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Release
if (RELEASE OR DEBUG STREQUAL "FALSE")
	set(RELEASE "TRUE")
endif()

# Debug
if (DEBUG OR RELEASE STREQUAL "DEBUG" OR RELEASE STREQUAL "FALSE")
	set(RELEASE "FALSE")
endif()

# add_definitions(-DWITH_PARALLEL)

# General C++ flags

	# General
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -std=c++11 -pedantic")

	# Release / Debug flags
	if (RELEASE)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -march=native -ffast-math")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
	endif()

# Boost
message(STATUS "---")
find_package(Boost REQUIRED)

# Qt 5
message(STATUS "---")
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5PrintSupport REQUIRED)
find_package(Qt5OpenGL REQUIRED)
set(qt5_libraries Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport Qt5::OpenGL)

# QCUSTOMPLOT
message(STATUS "---")
find_package(QCUSTOMPLOT REQUIRED)

if(QCUSTOMPLOT_FOUND)
	include_directories( ${QCUSTOMPLOT_INCLUDE_DIRS} )
	message(STATUS "QCustomPlot found =)")
else()
	message(STATUS "QCustomPlot not found! :(")
endif()

# OSG
message(STATUS "---")
find_package(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer)

if(OSG_FOUND AND OSGDB_FOUND AND OSGGA_FOUND AND OSGUTIL_FOUND AND OSGVIEWER_FOUND)
	include_directories( ${OPENSCENEGRAPH_INCLUDE_DIRS} )
	message(STATUS "OpenSceneGraph found =)")
else()
	message(STATUS "OpenSceneGraph not found! :(")
endif()

# Project
message(STATUS "---")
set(project_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")
include_directories("${project_INCLUDE}")
message(STATUS "Include project = ${project_INCLUDE}")


# Compiler log
message(STATUS "---")
message(STATUS "C++ compiler = ${CMAKE_CXX_COMPILER}")
message(STATUS "C++ flags    = ${CMAKE_CXX_FLAGS}")
if (RELEASE)
	message(STATUS "Release mode")
else()
	message(STATUS "Debug mode")
endif()

# Sources
file(GLOB_RECURSE project_sources src/*.cpp)
file(GLOB_RECURSE uis_forms src/*.ui)

# Executables
message(STATUS "---")
add_executable("brss" "exe/brss.cpp" "${project_sources}" "${uis_forms}")
target_link_libraries("brss" "${OPENSCENEGRAPH_LIBRARIES}" "${QCUSTOMPLOT_LIBRARIES}" "${qt5_libraries}")

# Test
message(STATUS "---")

if (DISABLE_TESTS)
	message(STATUS "Tests are disabled")
else()
	file(GLOB_RECURSE tests tests/*.cpp)
	foreach(test_source ${tests})
		string(REPLACE ".cpp" "" test_name ${test_source})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/tests/" "test__" test_name ${test_name})
		string(REPLACE "/" "_" test_name ${test_name})
		message(STATUS "Add test ${test_name}")
		add_executable(${test_name} "${test_source}")
	endforeach()
endif()
