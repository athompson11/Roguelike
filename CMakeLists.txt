cmake_minimum_required(VERSION 3.10)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("headers")
file(GLOB SOURCES "src/*.cpp")

# Check for build target and configure accordingly
if (BUILD_TARGET STREQUAL "NCURSES")
    # Find and include ncurses
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})

    # Build target for ncurses
    add_executable(engineTest ${SOURCES})
    target_compile_definitions(engineTest PRIVATE USE_NCURSES)
    target_link_libraries(engineTest ${CURSES_LIBRARIES})

elseif (BUILD_TARGET STREQUAL "SDL")
    # Find and include SDL2
    find_package(SDL2 REQUIRED)
    include_directories(${SDL2_INCLUDE_DIRS})

    # Build target for SDL
    add_executable(engineTest ${SOURCES})
    target_compile_definitions(engineTest PRIVATE USE_SDL)
    target_link_libraries(engineTest ${SDL2_LIBRARIES})

endif()