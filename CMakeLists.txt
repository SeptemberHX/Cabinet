cmake_minimum_required(VERSION 3.21)

project(Cabinet)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_PREFIX_PATH "/Users/septemberhx/Qt/6.2.3/macos/lib/cmake")

# generate a compile commands file as complete database for vim-YouCompleteMe or some other similar tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 COMPONENTS Widgets Core WebEngineWidgets REQUIRED)

file(GLOB_RECURSE SRCS
        "mainwindow.h"
        "main.cpp" "mainwindow.cpp"
        "items/*.cpp"
        "items/*.h"
        "widgets/*.cpp"
        "widgets/*.h"
        resources.qrc
        "widgets/*.ui"
        "widgets/todo/*.cpp"
        "widgets/todo/*.h")

add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(apis)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets Qt6::WebEngineWidgets Qt6::Gui apis)
