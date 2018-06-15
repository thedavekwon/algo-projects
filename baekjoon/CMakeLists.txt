cmake_minimum_required (VERSION 3.0)

project(baekjoon)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(13308 13308/13308.cpp)
add_executable(13302 13302/13302.cpp)
add_executable(13309 13309/13309.cpp)