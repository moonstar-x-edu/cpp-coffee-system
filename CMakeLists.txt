cmake_minimum_required(VERSION 3.15)
project(cpp_coffee_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_coffee_system src/main.cpp src/Client.cpp src/JSONFacade.cpp)

include_directories(lib)
include_directories(src)
