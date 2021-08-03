cmake_minimum_required(VERSION 3.20)
project(Workspace)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(Workspace main.cpp)
target_link_libraries(Workspace
        Qt5::Core
        )

