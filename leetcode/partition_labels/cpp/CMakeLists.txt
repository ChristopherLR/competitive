cmake_minimum_required(VERSION 3.20)

project(the_k_weakest_rows_in_a_matrix VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Catch2 3 REQUIRED)

include_directories(src)
add_subdirectory(src)

enable_testing()