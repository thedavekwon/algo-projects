cmake_minimum_required (VERSION 3.0)

project(leetcode)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(SplitArrayWithSameAverage 805/SplitArrayWithSameAverage.cpp)
add_executable(SplitArrayWithSameAverage2 805/SplitArrayWithSameAverage2.cpp)
add_executable(SplitArrayWithSameAverage3 805/SplitArrayWithSameAverage3.cpp)
add_executable(tmp 805/tmp.cpp)
add_executable(findMedianSortedArrays 4/findMedianSortedArrays.cpp)