#include <iostream>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>

#include "local_binary_pattern.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    string filename;

    if(argc != 2)
    {
        cout << "USAGE: ./lbp_image [IMAGE]\n";
        //        return 1;
        filename = "face.bmp";
    }
    else
    {
        filename = argv[1];
    }

    Mat image = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

    if(image.empty())
    {
        cout << "no image" << endl;
        return -1;
    }

    cv::imshow("image", image);

//    Mat lbp_image;
//    LBP(image, lbp_image);

//    //std::cout << image.size() << endl;

//    imshow("lbp", lbp_image);


    int bt = cv::getTickCount();
//    uniform_pattern(image, lbp_image);
    int et = cv::getTickCount();
    double t = (et - bt)*1000.0 / cv::getTickFrequency();
//    //printf("uniform_pattern : t = %f\n", t);

//    imshow("uniform lbp", lbp_image/10.0*255.0);

    int P = 24;
    int R = 3;
    int method = 0;
    cv::Mat uniform_lbp;
    cv::Mat norm_lbp_hist;
    bt = cv::getTickCount();
//    local_binary_pattern(image, P, R, 0, uniform_lbp);
    local_binary_pattern_histogram(image, P, R, method, norm_lbp_hist);
    cout << norm_lbp_hist << endl;
    et = cv::getTickCount();
    t = (et - bt)*1000.0 / cv::getTickFrequency();
    printf("local_binary_pattern : t = %f ms\n", t);

//    imshow("uniform_lbp", uniform_lbp/10.0*255.0);

    Mat norm_lbp_hist2;
    bt = cv::getTickCount();
    uniform_pattern_histogram(image, norm_lbp_hist2);
    et = cv::getTickCount();
    t = (et - bt)*1000.0 / cv::getTickFrequency();
    printf("uniform_pattern_histogram : t = %f\n", t);
    cout << "norm_lbp_hist: " << norm_lbp_hist2 << endl;

    waitKey(0);

    //    Mat spatial_hist;
    //    uniformPatternSpatialHistogram(lbp_img, spatial_hist, 256, cv::Size(3,3), 0);

    //    vector<int> feature_vector;
    //    for(int j = 0; j < spatial_hist.cols; ++j)
    //    {
    //        if(spatial_hist.at<int>(0, j) != -1)
    //            feature_vector.push_back(spatial_hist.at<int>(0, j));
    ////        else
    ////        {
    ////            cout << "err: -1" << endl;
    ////        }
    //    }

    //    cout << "********" << endl;

    //    for(int i = 0; i < feature_vector.size(); ++i)

    //    {
    //        if(i != (feature_vector.size() - 1))
    //            cout << feature_vector[i] << " ";
    //        else
    //            cout << feature_vector[i];
    //    }
    //    cout << "\n";
    return 0;

}

