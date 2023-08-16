cmake_minimum_required(VERSION 3.24)

# Prevent CMake from trying to find Vulkan headers
set(CMAKE_FIND_PACKAGE_NO_PACKAGE_REGISTRY ON)

project(analog_simulator)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_executable(analog_simulator
        src/Main.cpp
        src/Component.cpp
        src/Circuit.cpp
        src/components/Resistor.cpp)

# Add the ./includes/ directory to include path
target_include_directories(analog_simulator PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
        ${CMAKE_CURRENT_SOURCE_DIR}/includes/components)
