cmake_minimum_required(VERSION 3.25)
project(GUI)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED)
include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

add_executable(GUI src/Window.cpp src/Window.h src/main.cpp src/widgets/Frame.cpp src/widgets/Frame.h src/math/utils.cpp src/math/utils.h src/misc/colors.h src/widgets/Button.cpp src/widgets/Button.h src/widgets/Widget.h src/widgets/Widget.cpp src/misc/enums.h src/renderer/Renderer.h)

target_link_libraries(GUI ${SDL2_LIBRARIES})
