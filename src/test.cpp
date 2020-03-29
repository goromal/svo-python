#include "svo/monocular_svo.h"
#include "logging-utils-lib/logging.h"
#include "logging-utils-lib/filesystem.h"
#include "geometry-utils-lib/xform.h"
#include <opencv2/opencv.hpp>
#include <Eigen/Core>
#include <vector>
#include <iostream>

int main()
{
//    std::string vid_path = "../test/travel.mp4";
    std::string vid_path = "../test/short.MOV";
    std::string vid_dir = filesys::dirName(vid_path);

    cv::VideoCapture cap(vid_path);

    svo::MonocularSVO msvo;
    std::vector<double> cam_params = {1920, 1080, 700.0, 700.0, 960.0, 540.0, 0.0, 0.0, 0.0, 0.0};
    std::cout << msvo << std::endl;
    msvo.initialize("Pinhole", cam_params);
    std::cout << msvo << std::endl;

    const double dt = 1/30.0;

    unsigned int i = 0;
    while (cap.isOpened())
    {
        double t = (i-1) * dt;
        std::cout << "Processing frame " << i << "..." << std::endl;
        cv::Mat frame, frame_bw;

        if (!cap.read(frame))
            break;

        cv::cvtColor(frame, frame_bw, cv::COLOR_BGR2GRAY);
        std::cout << "Updating...";
        msvo.update(frame_bw, t);
        std::cout << "done." << std::endl;

        Eigen::Vector3d trans;
        Eigen::Matrix3d Rot;
        msvo.getPose(trans, Rot);

//        std::cout << trans.transpose() << std::endl;
//        std::cout << Rot << std::endl;

//        transforms::Xformd X(trans, transforms::Quatd::from_R(Rot));
//        Eigen::MatrixXd Xelem;
//        Xelem.resize(7, 1);
//        Xelem.col(0) = X.elements();
//        logging::matrixToLog(vid_dir + "/travelX.log", Xelem, true);

        i++;
    }

    return 0;
}
