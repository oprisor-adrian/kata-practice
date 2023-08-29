cmake_minimum_required(VERSION 3.2)
project(kata-01)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)
include_directories(include/)
add_executable(${CMAKE_PROJECT_NAME}
  main.cpp
  src/rail_cipher.cpp
)