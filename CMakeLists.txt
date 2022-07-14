cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(learn_cpp)

add_subdirectory(multi_threading)
add_subdirectory(moderncpp)
add_subdirectory(webserver)