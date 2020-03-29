//#include "svo/monocular_svo.h"
#include <pybind11/pybind11.h>
#include <pybind11/eigen.h>
#include <pybind11/stl.h>
#include <pybind11/operators.h>
#include <sstream>

using namespace Eigen;
namespace py = pybind11;

// https://stackoverflow.com/questions/59525460/error-segmentation-fault-core-dumped-when-import-module-built-from-pybind11
// https://pybind11-rtdtest.readthedocs.io/en/stable/advanced.html
// https://www.reddit.com/r/Python/comments/ajyw7a/pybind11_exporting_interface_of_large_c_library/
//

PYBIND11_MODULE(svo_mono, m)
{
    m.doc() = "Python binding module for the monocular semi-direct visual odometry algorithm.";

//   py::class_<svo::MonocularSVO>(m, "MonocularSVO")
//           .def(py::init())
//           .def("initialize", &svo::MonocularSVO::initialize)
//           .def("update", &svo::MonocularSVO::update)
//           .def("getPose", &svo::MonocularSVO::getPose)
//           .def("__repr__",
//                [](const svo::MonocularSVO &msvo) {
//       std::stringstream ss;
//       ss << msvo;
//       return ss.str();
//   }
//   );
}
