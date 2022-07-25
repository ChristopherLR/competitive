set(SOURCE_FILES
  tests.cpp
  solution.cpp
)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)