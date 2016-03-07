cmake_minimum_required(VERSION 3.3)
project(SubmitPorn)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -D_GLIBCXX_DEBUG")

set(SOURCE_FILES main.cpp DataStructures/segment_tree.h)
add_executable(SubmitPorn ${SOURCE_FILES})