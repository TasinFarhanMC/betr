cmake_minimum_required(VERSION 3.10)

project(
  BETR
  VERSION 1.0.0
  DESCRIPTION "A C++ Library With Better Standards"
  HOMEPAGE_URL "https://github.com/TasinFarhanMC/betr"
  LANGUAGES CXX)

add_library(betr INTERFACE)
target_include_directories(
  betr INTERFACE "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src>")

install(
  TARGETS betr
  EXPORT BetrTargets
  INCLUDES
  DESTINATION include)

install(
  DIRECTORY src/
  DESTINATION include
  FILES_MATCHING
  PATTERN "*.hpp")

install(
  EXPORT BetrTargets
  FILE BetrTargets.cmake
  NAMESPACE Betr::
  DESTINATION lib/cmake/Betr)

include(CMakePackageConfigHelpers)
configure_package_config_file(
  "${CMAKE_SOURCE_DIR}/BetrConfig.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/BetrConfig.cmake"
  INSTALL_DESTINATION lib/cmake/Betr)

install(FILES "${CMAKE_CURRENT_BINARY_DIR}/BetrConfig.cmake"
        DESTINATION lib/cmake/Betr)

include(CPack)

set(CPACK_PACKAGE_NAME "Betr")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${PROJECT_DESCRIPTION}")
set(CPACK_PACKAGE_HOMEPAGE_URL "${PROJECT_HOMEPAGE_URL}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE-MIT.txt")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

set(CPACK_GENERATOR "DEB;RPM;ZIP;NuGet;DragNDrop;WIX")
