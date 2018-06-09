cmake_minimum_required (VERSION 3.0)

project(uva)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(11450 11450/11450.cpp)
add_executable(507 507/507.cpp)
add_executable(answer 507/answer.cpp)
add_executable(108 108/108.cpp)
add_executable(10130 10130/10130.cpp)
add_executable(674 674/674.cpp)