cmake_minimum_required(VERSION 3.4)
project(example)

get_filename_component(PARENT_DIR ${CMAKE_SOURCE_DIR} DIRECTORY)
get_filename_component(ROOT_DIR ${PARENT_DIR} DIRECTORY)
# cmake：add_subdirectory() 注意事项
# https://zhuanlan.zhihu.com/p/85980099
add_subdirectory(${ROOT_DIR}/lib/pybind11 lib/pybind11)

# Source files
FILE(GLOB_RECURSE SOURCE_FILES
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/src/*.cc"
    "${CMAKE_SOURCE_DIR}/src/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE 
    pybind11::embed)

# Python Module files
FILE(GLOB_RECURSE PYTHON_MODULE_FILES
    "${CMAKE_SOURCE_DIR}/src/modules/*.py"
)

if(NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  file(COPY ${PYTHON_MODULE_FILES} DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/modules")
endif()

