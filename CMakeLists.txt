cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 0.1.1
  DESCRIPTION "A C++ Library With Better Standards"
  LANGUAGES CXX)

add_library(betr INTERFACE)
target_include_directories(betr PUBLIC "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>")
