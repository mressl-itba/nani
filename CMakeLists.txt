cmake_minimum_required(VERSION 3.22)
project(nani)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/6.0.tar.gz
)

FetchContent_MakeAvailable(raylib)

add_executable(nani
    src/main.cpp
    src/ui.cpp
    src/nani/csv.cpp
    src/nani/nani.cpp)

target_link_libraries(nani PRIVATE raylib)
