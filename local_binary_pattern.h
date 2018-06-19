/*
Author: tim
Email: tim.zhong@irisian.com
Function: LBP
*/

#ifndef LOCAL_BINARY_PATTERN_H
#define LOCAL_BINARY_PATTERN_H

#include <opencv2/opencv.hpp>

void compute_LBP_1_8_hist(const cv::Mat& image, cv::Mat &lbps_hist);
void compute_LBP_2_16_hist(const cv::Mat& image, cv::Mat &lbps_hist);
void compute_LBP_3_24_hist(const cv::Mat& image, cv::Mat &lbps_hist);

void compute_lbps_hist(const cv::Mat& image, cv::Mat &lbps_hist);

cv::Mat compute_lbps_hist(const cv::Mat& image);

double bilinear_interpolation(const cv::Mat &image, double r, double c);

void local_binary_pattern(const cv::Mat &image, int P, int R, int method, cv::Mat &lbp_image);

void local_binary_pattern_histogram(const cv::Mat& image, int P, int R, int method, cv::Mat &norm_lbp_hist);

cv::Mat local_binary_pattern(const cv::Mat &image, int P, int R, int method);

cv::Mat local_binary_pattern_histogram(const cv::Mat& image, int P, int R, int method);


/**
 * @brief get_texture : 获取中心点的8领域像素点的像素值
 * @param image
 * @param rows
 * @param cols
 * @param r
 * @param c
 * @param i
 * @return
 */
uchar get_texture(const cv::Mat &image, int rows, int cols, int r, int c, int i);

/**
 * @brief uniform_pattern: 3x3 LBP , (P,R) = (8,1)
 * @param image : gray scale
 * @param lbp : gray scale
 */
void uniform_pattern(const cv::Mat &image, cv::Mat &lbp_image);

/**
 * @brief uniform_pattern_histogram : 3x3 LBP(1,8)
 * @param lbp_image : gray scale
 * @param hist : 10 bins
 */
void uniform_pattern_histogram(const cv::Mat& image, cv::Mat &norm_lbp_hist);

void LBP(const cv::Mat& image, cv::Mat& lbp_image);

#endif // LOCAL_BINARY_PATTERN_H
