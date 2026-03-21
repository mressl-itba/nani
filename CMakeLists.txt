cmake_minimum_required(VERSION 3.22)
project(nani)

set(CMAKE_CXX_STANDARD 20)

find_package(raylib CONFIG REQUIRED)

add_executable(nani 
    src/main.cpp
    src/ui.cpp
    src/nani/csv.cpp
    src/nani/nani.cpp)

target_link_libraries(nani PRIVATE raylib)
