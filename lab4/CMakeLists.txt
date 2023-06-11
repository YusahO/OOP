cmake_minimum_required(VERSION 3.0)
project(lab4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)

file(GLOB sources
        ./lib/button/Button.cpp
        ./lib/cabin/Cabin.cpp
        ./lib/controller/Controller.cpp
        ./lib/doors/Doors.cpp
        ./lib/elevator/Elevator.cpp
        ./gui/mainwindow.cpp
        ./main.cpp
        )
add_executable(${PROJECT_NAME} ${sources})

target_include_directories(${PROJECT_NAME} PRIVATE
        ./lib/
        ./gui/ui
        ./lib/button
        ./lib/cabin
        ./lib/controller
        ./lib/doors
        ./lib/elevator
        ./gui

        )

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})