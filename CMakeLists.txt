cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(ImagineTasks)

add_executable(${PROJECT_NAME}
  main.cpp
)

target_link_libraries( ${PROJECT_NAME}
  PUBLIC
    pangrams
    particles
    rotation
)


add_subdirectory (pangrams)
add_subdirectory (particles)
add_subdirectory (rotation)