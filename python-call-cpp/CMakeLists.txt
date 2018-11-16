cmake_minimum_required(VERSION 2.8.12)
project(example)

add_subdirectory(lib/pybind11)
pybind11_add_module(${PROJECT_NAME} src/main.cpp)
