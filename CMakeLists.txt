cmake_minimum_required(VERSION 2.8.12)
project(svo-python)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Eigen3 REQUIRED)
add_subdirectory(lib/svo)
add_subdirectory(lib/pybind11)

include_directories(
  lib/svo/include
  lib/svo/lib/vikit_common/include
  lib/svo/lib/vikit_common/lib/Sophus
  ${EIGEN3_INCLUDE_DIRS}
)

pybind11_add_module(svo_mono src/svo_mono.cpp)
