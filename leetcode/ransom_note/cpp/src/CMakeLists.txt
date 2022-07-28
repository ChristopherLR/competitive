set(SOURCE_FILES
  solution.cpp
)

add_executable(solution solution.cpp)
target_link_libraries(solution PRIVATE Catch2::Catch2WithMain)