cmake_minimum_required(VERSION 3.4)
project(example)

get_filename_component(PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
# cmake：add_subdirectory() 注意事项
# https://zhuanlan.zhihu.com/p/85980099
add_subdirectory(${PARENT_DIR}/lib/pybind11 lib/pybind11)

# Source files
FILE(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cc"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

pybind11_add_module(${PROJECT_NAME} ${SOURCE_FILES})
