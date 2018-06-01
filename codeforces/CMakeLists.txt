cmake_minimum_required (VERSION 3.0)

project(codeforces)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")
add_executable(D BetaRound11/D.cpp)