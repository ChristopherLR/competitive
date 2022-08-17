cmake_minimum_required(VERSION 3.20)

project(permutations VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Catch2 3 REQUIRED)

enable_testing()

include_directories(src)
add_subdirectory(src)