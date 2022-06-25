cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(moderncpp LANGUAGES CXX)

find_package (Threads REQUIRED)

include(GNUInstallDirs)
include(CheckAndAddFiles)

#add source files
check_and_add_files(SOURCE_FILES
 "./"
  a.cc
)

add_executable(moderncpp ${SOURCE_FILES})

target_link_libraries(moderncpp
  PRIVATE
    Threads::Threads
)