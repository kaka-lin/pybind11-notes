cmake_minimum_required(VERSION 2.8.12)
project(example)

add_subdirectory(lib/pybind11)

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE pybind11::embed)
