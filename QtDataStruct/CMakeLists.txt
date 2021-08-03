cmake_minimum_required(VERSION 3.20)
project(QtDataStruct)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories(include)
aux_source_directory(src)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_executable(QtDataStruct src/main.cpp)
target_link_libraries(QtDataStruct
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

