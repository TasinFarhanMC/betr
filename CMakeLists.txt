cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 0.2.5
  DESCRIPTION "A C++ Library With Better Standards"
  LANGUAGES CXX)

add_library(Betr INTERFACE)
target_include_directories(Betr INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_compile_features(Betr PUBLIC cxx_std_23)
set_property(TARGET Betr PROPERTY CXX_SCAN_FOR_MODULES OFF)
