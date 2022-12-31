cmake_minimum_required(VERSION 3.12)

# Set some basic project attributes
project (EcoStruxure
		VERSION 0.0.0.6
		DESCRIPTION "EcoStruxure Runtime plugin")
		
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB SOURCES "src/Plugin.cpp" "src/*/*.cpp")

add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Create a simple configuration header
configure_file(config.h.in config.h)

include_directories("${PROJECT_BINARY_DIR}" include)

message("CMAKE_PROJECT_VERSION = ${CMAKE_PROJECT_VERSION}")

set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})
