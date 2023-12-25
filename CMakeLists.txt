cmake_minimum_required(VERSION 3.10)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("headers")

file(GLOB SOURCES "src/*.cpp")
add_executable(engineTest ${SOURCES})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(engineTest ${CURSES_LIBRARIES})

