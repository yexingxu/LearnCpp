cmake_minimum_required(VERSION 3.8)
project(cpp-concurrency)

set(CMAKE_CXX_COMPILER "g++-9")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)

add_executable(multicast_send  multicast_send.cc)
add_executable(multicast_recv  multicast_recv.cc)
add_executable(unicast_send  unicast_send.cc)
add_executable(unicast_recv  unicast_recv.cc)