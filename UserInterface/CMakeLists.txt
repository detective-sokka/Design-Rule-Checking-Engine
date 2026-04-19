cmake_minimum_required(VERSION 3.16)
project(drc_ui VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(drc_ui
    src/main.cpp
    src/MainWindow.cpp
)

target_include_directories(drc_ui PRIVATE include)

target_link_libraries(drc_ui PRIVATE Qt6::Widgets)

set_target_properties(drc_ui PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
