enable_testing()
find_package(GTest REQUIRED)
add_executable(${CMAKE_PROJECT_NAME}_test
  test_rail_cipher.cpp
)
target_link_libraries(${CMAKE_PROJECT_NAME}_test
  GTest::gtest_main
  ${CMAKE_PROJECT_NAME}_lib
)
include(GoogleTest)
gtest_discover_tests(${CMAKE_PROJECT_NAME}_test)
