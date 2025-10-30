cmake_minimum_required(VERSION 3.16)
project(slim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include headers
include_directories(include)

# Collect all .cpp files
file(GLOB SOURCES "src/*.cpp")

# Build the executable
add_executable(slim ${SOURCES})
