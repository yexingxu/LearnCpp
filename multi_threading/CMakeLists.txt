cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(multi_thread LANGUAGES CXX)

find_package (Threads REQUIRED)

include(GNUInstallDirs)
include(CheckAndAddFiles)

#add source files
check_and_add_files(SOURCE_FILES
"./"
  1-1.cc
)

add_executable(multi_thread ${SOURCE_FILES})

target_link_libraries(multi_thread
  PRIVATE
    Threads::Threads
)

add_subdirectory(src)