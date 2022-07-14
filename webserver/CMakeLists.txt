cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(webserver LANGUAGES CXX)

find_package (Threads REQUIRED)

include(GNUInstallDirs)
include(CheckAndAddFiles)

#add source files
check_and_add_files(SOURCE_FILES
 "./"
  main.cc
)

add_executable(webserver ${SOURCE_FILES})

target_link_libraries(webserver
  PRIVATE
    Threads::Threads
)
add_subdirectory(udpreuse)
