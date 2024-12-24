cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 0.2.0
  DESCRIPTION "A C++ Library With Better Standards"
  LANGUAGES CXX)

add_library(betr INTERFACE)
target_include_directories(betr INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
