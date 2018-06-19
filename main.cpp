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

    cv::resize(image, image, cv::Size(200, 200));

    cv::imshow("image", image);


    cv::Mat lbp_hist;
    compute_LBP_1_8_hist(image, lbp_hist);
    cout << "lbp18: " << lbp_hist << endl;
    compute_LBP_2_16_hist(image, lbp_hist);
    cout << "lbp216: " << lbp_hist << endl;
    compute_LBP_3_24_hist(image, lbp_hist);
    cout << "lbp324: " << lbp_hist << endl;

    Mat lbp_image;
    LBP(image, lbp_image);

//    std::cout << image.size() << endl;

    imshow("lbp", lbp_image);

//    cv::Mat lbp_image;

    int bt = cv::getTickCount();
    uniform_pattern(image, lbp_image);
    int et = cv::getTickCount();
    double t = (et - bt)*1000.0 / cv::getTickFrequency();
    printf("uniform_pattern : t = %d ms\n", (int)t);

    imshow("uniform lbp", lbp_image/10.0*255.0);

    int P = 8;
    int R = 1;
    int method = 0;
    cv::Mat uniform_lbp;
    cv::Mat norm_lbp_hist;

    bt = cv::getTickCount();

    uniform_lbp = local_binary_pattern(image, P, R, method);
    norm_lbp_hist = local_binary_pattern_histogram(image, P, R, method);

    et = cv::getTickCount();
    t = (et - bt)*1000.0 / cv::getTickFrequency();
    printf("local_binary_pattern : t = %d ms\n", (int)t);

    cout << norm_lbp_hist << endl;

    imshow("uniform_lbp", uniform_lbp/10.0*255.0);


    waitKey(0);

    return 0;

}

