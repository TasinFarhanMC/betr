cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 0.2.5
  DESCRIPTION "A C++ Library With Better Standards"
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(betr INTERFACE)
target_include_directories(betr INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
