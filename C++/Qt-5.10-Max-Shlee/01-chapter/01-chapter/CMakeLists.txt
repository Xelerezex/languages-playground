# sudo apt-get install qtbase5-dev
# sudo apt-get install qtdeclarative5-dev
#
# cmake .. \
#    -DCMAKE_PREFIX_PATH=/opt/QT/5.15.2/gcc_64/lib/cmake          \
#    -DQt5Core_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Core        \
#    -DQt5Gui_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Gui          \
#    -DQt5Widgets_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Widgets

cmake_minimum_required(VERSION 3.16)
project(first)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")

set(CMAKE_PREFIX_PATH "/opt/Qt")

# find_package(Qt5Core REQUIRED)
# find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILE 00-qt-hello.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILE})

# target_link_libraries(${PROJECT_NAME} Qt5::Core)
# target_link_libraries(${PROJECT_NAME} Qt5::Gui)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
