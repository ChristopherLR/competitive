file(GLOB SOURCE_FILES "*.cpp")

file(GLOB HEADER_FILES "*.h")

add_executable(solution solution.cpp)
target_link_libraries(solution PRIVATE Catch2::Catch2WithMain)