#include "svo/monocular_svo.h"
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <sstream>

using namespace Eigen;
namespace py = pybind11;

PYBIND11_MODULE(utils_quat, m)
{
    m.doc() = "Python binding module for the monocular semi-direct visual odometry algorithm.";

   py::class_<svo::MonocularSVO>(m, "MonocularSVO")
           .def(py::init())
           .def("initialize", &svo::MonocularSVO::initialize)
           .def("update", &svo::MonocularSVO::update)
           .def("getPose", &svo::MonocularSVO::getPose)
           .def("__repr__",
                [](const svo::MonocularSVO &msvo) {
       std::stringstream ss;
       ss << msvo;
       return ss.str();
   }
   );
}
