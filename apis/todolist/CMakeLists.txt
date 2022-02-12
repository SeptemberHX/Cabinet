cmake_minimum_required(VERSION 3.21)

project(todolist)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_PREFIX_PATH "/Users/septemberhx/Qt/6.2.3/macos/lib/cmake")

# generate a compile commands file as complete database for vim-YouCompleteMe or some other similar tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 COMPONENTS Core WebEngineWidgets REQUIRED)

set(SRCS
        "dida365/DiDa365Tools.cpp"
        "dida365/DiDa365Tools.h"
        dida365/DiDaTask.cpp dida365/DiDaTask.h

        TodoItem.cpp TodoItem.h dida365/DiDaProject.cpp dida365/DiDaProject.h dida365/DiDaGroup.cpp dida365/DiDaGroup.h dida365/DiDaTag.cpp dida365/DiDaTag.h)

add_library(${PROJECT_NAME} STATIC ${SRCS})

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::WebEngineWidgets)
