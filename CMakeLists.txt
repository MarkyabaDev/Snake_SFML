cmake_minimum_required(VERSION 3.22)
project(Snake)

set(CMAKE_CXX_STANDARD 14)
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR D:/Projekte/C++/SFML-2.5.1/lib/cmake/SFML)

add_executable(Snake main.cpp Window.cpp Window.h Game.cpp Game.h)
find_package(SFML COMPONENTS system graphics audio network window REQUIRED)
include_directories(D:/Projekte/C++/SFML-2.5.1/include)

target_link_libraries(Snake sfml-system sfml-graphics sfml-audio sfml-network sfml-window)
