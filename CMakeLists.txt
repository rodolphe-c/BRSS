# Copyright � 2017 Rodolphe Cargnello, rodolphe.cargnello@gmail.com

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
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wconversion -Wsign-conversion -std=c++14 -pedantic")

	# Release / Debug flags
	if (RELEASE)
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -march=native -ffast-math")
	else()
		set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g3")
	endif()

# Qt 5
    message(STATUS "---")
	find_package(Qt5Core REQUIRED)
	find_package(Qt5Gui REQUIRED)
	find_package(Qt5Widgets REQUIRED)
	find_package(Qt5PrintSupport REQUIRED)
	find_package(Qt5OpenGL REQUIRED)

	set(qt5_libraries Qt5::Core Qt5::Gui Qt5::Widgets Qt5::PrintSupport Qt5::OpenGL)
	message(STATUS "Qt5 found =)")
    link_libraries(${qt5_libraries})

# QCUSTOMPLOT
    message(STATUS "---")
	find_package(QCUSTOMPLOT REQUIRED)

	if(QCUSTOMPLOT_FOUND)
		include_directories( ${QCUSTOMPLOT_INCLUDE_DIRS} )
		link_libraries(${QCUSTOMPLOT_LIBRARIES})

		message(STATUS "QCustomPlot found =)")
    else()
		message(STATUS "QCustomPlot not found! :(")
	endif()

# OSG
    message(STATUS "---")
	find_package(OpenSceneGraph REQUIRED COMPONENTS osgDB osgGA osgUtil osgViewer)

if(OSG_FOUND AND OSGDB_FOUND AND OSGGA_FOUND AND OSGUTIL_FOUND AND OSGVIEWER_FOUND)
	include_directories( ${OPENSCENEGRAPH_INCLUDE_DIRS} )
	link_libraries(${OPENSCENEGRAPH_LIBRARIES})
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

# Executables

    file(GLOB_RECURSE uis_forms src/*.ui)

	message(STATUS "---")

	file(GLOB_RECURSE exes exe/*.cpp)

	foreach(exe_source ${exes})

		# Get exe name and source
		string(REPLACE ".cpp" "" exe_name ${exe_source})
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/exe/" "" exe_name ${exe_name})
		string(REPLACE "/" "_" exe_name ${exe_name})

		message(STATUS "Add exe ${exe_name}")

		add_executable(${exe_name} "${exe_source}" "${project_sources}" "${uis_forms}")

	endforeach()
