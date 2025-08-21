cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 0.2.6
  DESCRIPTION "A C++ Library With Better Standards"
  LANGUAGES CXX)

add_library(betr INTERFACE)
target_include_directories(betr INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
set_target_properties(betr PROPERTIES CXX_SCAN_FOR_MODULES OFF)
target_compile_features(betr INTERFACE cxx_std_23)
