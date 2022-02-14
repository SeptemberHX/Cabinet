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

find_package(Qt6 COMPONENTS Widgets Core WebEngineWidgets Sql REQUIRED)

set(SRCS
        "mainwindow.h"
        "main.cpp" "mainwindow.cpp"
        "items/PreviewMDDoc.h" "items/PreviewMDDoc.cpp"
        "widgets/PreviewPage.h" "widgets/PreviewPage.cpp"
        "widgets/CabinetMainWidget.h" "widgets/CabinetMainWidget.cpp" "widgets/CabinetMainWidget.ui"
        "widgets/FileListWidget.h" "widgets/FileListWidget.cpp" "widgets/FileListWidget.ui"
        resources.qrc
        "widgets/todo/TodoPage.h" "widgets/todo/TodoPage.cpp" "widgets/todo/TodoPage.ui"
        "widgets/todo/TodoItemWidget.h" "widgets/todo/TodoItemWidget.cpp" "widgets/todo/TodoItemWidget.ui" CabinetSettings.cpp CabinetSettings.h items/CabinetDB.cpp items/CabinetDB.h items/TodoItemRecord.cpp items/TodoItemRecord.h)

add_executable(${PROJECT_NAME} ${SRCS})

add_subdirectory(apis)

target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets Qt6::WebEngineWidgets Qt6::Gui apis Qt6::Sql)
