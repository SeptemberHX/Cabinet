cmake_minimum_required(VERSION 3.21)

project(apis)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_PREFIX_PATH "/Users/septemberhx/Qt/6.2.3/macos/lib/cmake")

# generate a compile commands file as complete database for vim-YouCompleteMe or some other similar tools
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 COMPONENTS Gui Core WebEngineWidgets REQUIRED)

add_subdirectory(todolist)

add_library(${PROJECT_NAME} INTERFACE)

add_executable(${PROJECT_NAME}-test  test/TodoListTest.cpp test/TodoListTest.h test/MainTest.cpp)

target_link_libraries(${PROJECT_NAME} INTERFACE todolist)

target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})