cmake_minimum_required(VERSION 3.2)
project(lfc-gri)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)
add_executable(${CMAKE_PROJECT_NAME}
  main.cpp
  src/application.cpp
  src/grammar.cpp
  src/production.cpp
)