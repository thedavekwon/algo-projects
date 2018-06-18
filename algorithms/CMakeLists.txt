cmake_minimum_required(VERSION 2.8)

project(algorithms)

set(CMAKE_CXX_STANDARD 11)
add_executable(karatsuba math/karatsuba.cpp)
add_executable(tree data_structure/tree.cpp)
add_executable(mean_error_square math/mean_error_square.cpp)