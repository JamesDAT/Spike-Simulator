cmake_minimum_required(VERSION 3.26)
project(Spike_Simulator LANGUAGES CXX)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Detect the compiler and set the build directory
if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(PLATFORM "windows")
    add_compile_options(/experimental:module /std:c++latest)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(PLATFORM "linux")
    add_compile_options(-fmodules -std=c++23)
else()
    message(FATAL_ERROR "Unsupported compiler")
endif()

# Create platform-specific build directories
set(BUILD_DIR "${CMAKE_SOURCE_DIR}/build/${PLATFORM}")
file(MAKE_DIRECTORY ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})

# Collect all source files (.cpp and .cppm) from the src directory
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.cppm)

# Create the executable
add_executable(Spike_Simulator ${SOURCES})

# Include directories
target_include_directories(Spike_Simulator PRIVATE ${CMAKE_SOURCE_DIR}/include)
