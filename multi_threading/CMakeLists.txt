cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

project(multi_thread LANGUAGES CXX)

find_package (Threads REQUIRED)

include(GNUInstallDirs)
include(CheckAndAddFiles)

#add source files
check_and_add_files(SOURCE_FILES
  1-1.cc
)

add_executable(multi_thread 1-1.cc)

target_link_libraries(multi_thread
  PRIVATE
    Threads::Threads
)