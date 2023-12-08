cmake_minimum_required(VERSION 3.2)
project(cezar_cipher)
set(CXX_STANDARD 14)
set(CXX_STANDARD_REQUIRED true)
include_directories(include)
add_executable(${CMAKE_PROJECT_NAME}
  main.cpp
  src/caesar_cipher.cpp
)
add_library(${CMAKE_PROJECT_NAME}_lib
  main.cpp
  src/caesar_cipher.cpp
)
add_subdirectory(test)