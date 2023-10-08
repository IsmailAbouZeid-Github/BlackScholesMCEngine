cmake_minimum_required(VERSION 3.10)
project(BSM)
# Set C++ version
set(CMAKE_CXX_STANDARD 14)
# Include directories
include_directories(include)
# Add an executable target
add_executable(Main src/BSM.cpp src/main.cpp)
