cmake_minimum_required(VERSION 3.15)
project(cpp_coffee_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_coffee_system src/main.cpp src/Client.cpp src/Client.h src/JSONFacade.cpp src/JSONFacade.h src/Coffee.cpp src/Coffee.h src/Enums.cpp src/Enums.h)

include_directories(lib)
include_directories(src)
