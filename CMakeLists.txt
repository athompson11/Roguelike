cmake_minimum_required(VERSION 3.10)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("headers")

file(GLOB SOURCES "src/*.cpp")

# Find ncurses
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Build target for ncurses
add_executable(engineTest_ncurses ${SOURCES})
target_compile_definitions(engineTest_ncurses PRIVATE USE_NCURSES)
target_link_libraries(engineTest_ncurses ${CURSES_LIBRARIES})

# Build target for SDL
add_executable(engineTest_sdl ${SOURCES})
target_compile_definitions(engineTest_sdl PRIVATE USE_SDL)
target_link_libraries(engineTest_sdl ${SDL2_LIBRARIES})