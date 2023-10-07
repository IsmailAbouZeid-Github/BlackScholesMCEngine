cmake_minimum_required(VERSION 3.10)

project(BSM)

# Set C++ version
set(CMAKE_CXX_STANDARD 14)

include_directories(include)
# Specify the source files
set(SOURCES
    src/bsm.cpp
)

# Add an executable target
add_executable(BSM src/BSM.cpp)
# Include directories

