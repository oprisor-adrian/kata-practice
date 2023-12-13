cmake_minimum_required(VERSION 3.2)
project(kata-03)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)
add_executable(${CMAKE_PROJECT_NAME}
  main.cpp
  src/afile_cipher.cpp
)
add_library(${CMAKE_PROJECT_NAME}_lib
  main.cpp
  src/afile_cipher.cpp
)
add_subdirectory(test/)