cmake_minimum_required(VERSION 2.8.12)
project(svo-python)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET( CMAKE_BUILD_TYPE Debug )

find_package(Eigen3 REQUIRED)
add_subdirectory(lib/svo)
add_subdirectory(lib/geometry-utils-lib)
add_subdirectory(lib/logging-utils-lib)
#add_subdirectory(lib/pybind11)

include_directories(
  lib/svo/include
  lib/svo/lib/vikit_common/include
  lib/svo/lib/vikit_common/lib/Sophus
  lib/geometry-utils-lib/include
  lib/logging-utils-lib/include
  ${EIGEN3_INCLUDE_DIRS}
)

add_executable(test src/test.cpp)
target_link_libraries(test svo geometry-utils-lib logging-utils-lib)

#pybind11_add_module(svo_mono src/svo_mono.cpp)
