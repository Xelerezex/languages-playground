# sudo apt-get install qtbase5-dev
# sudo apt-get install qtdeclarative5-dev
#
# cmake .. \
#    -DCMAKE_PREFIX_PATH=/opt/QT/5.15.2/gcc_64/lib/cmake          \
#    -DQt5Core_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Core        \
#    -DQt5Gui_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Gui          \
#    -DQt5Widgets_DIR=/opt/QT/5.15.2/gcc_64/lib/cmake/Qt5Widgets


cmake_minimum_required(VERSION 3.16)
project(Tulip)


set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")


set(CMAKE_PREFIX_PATH "/opt/Qt")
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


add_executable(${PROJECT_NAME}
	tulip.cpp
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		Qt5::Widgets
		Qt5::Core
)
