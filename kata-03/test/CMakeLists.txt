enable_testing()
find_package(GTest REQUIRED)
include(GoogleTest)
add_executable(${CMAKE_PROJECT_NAME}_test
  test_affine_cipher.cpp 
)
target_link_libraries(${CMAKE_PROJECT_NAME}_test
  GTest::gtest_main
  ${CMAKE_PROJECT_NAME}_lib
)