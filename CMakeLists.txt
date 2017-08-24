cmake_minimum_required(VERSION 3.7)
project(Kmeans)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Kmeans.cpp Kmeans.h)
add_executable(Kmeans ${SOURCE_FILES})