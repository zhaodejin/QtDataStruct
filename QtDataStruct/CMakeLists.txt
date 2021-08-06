cmake_minimum_required(VERSION 3.0)
project(MakeMoney)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/home/zhaodejin/Qt5.9.0/5.9/gcc_64")
set(Qt5_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5")
#set(Qt5Widgets_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Widgets")
#set(Qt5Network_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5Network")
#set(Qt5LinguistTools_DIR "${CMAKE_PREFIX_PATH}/lib/cmake/Qt5LinguistTools")
#find_package(Qt5 COMPONENTS Widgets Network LinguistTools)
include_directories(include)
#aux_source_directory(src)

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

