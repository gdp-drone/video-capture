cmake_minimum_required(VERSION 3.13)
project(video_capture)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(video_capture main.cpp)

target_link_libraries(video_capture ${OpenCV_LIBS})