cmake_minimum_required(VERSION 2.8)

project(program)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(cv_program program.cpp)

target_link_libraries(cv_program ${OpenCV_LIBS})
