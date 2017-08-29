#include "local_binary_pattern.h"

#include <iostream>

using namespace std;

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
uchar get_texture(const cv::Mat &image, int rows, int cols, int r, int c, int i)
{
    uchar texture = 0;
    if(r == 0 && c == 0)
    {
        if(i == 0)
        {}
        else if( i == 1)
        {}
        else if( i == 2)
        {}
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
            texture = image.at<uchar>(r + 1, c + 1);
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
        {}
        else if( i == 7)
        {}
    }
    else if( r == 0 && c > 0 && c < cols - 1)
    {
        if(i == 0)
        {}
        else if( i == 1)
        {}
        else if( i == 2)
        {}
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
            texture = image.at<uchar>(r + 1, c + 1);
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
            texture = image.at<uchar>(r + 1, c - 1);
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    else if( r == 0 && c == cols - 1)
    {
        if(i == 0)
        {}
        else if( i == 1)
        {}
        else if( i == 2)
        {}
        else if( i == 3)
        {}
        else if( i == 4)
        {}
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
            texture = image.at<uchar>(r + 1, c - 1);
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    else if( r > 0 && r < rows -1 && c == cols - 1)
    {
        if(i == 0)
            texture = image.at<uchar>(r - 1, c - 1);
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
        {}
        else if( i == 3)
        {}
        else if( i == 4)
        {}
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
            texture = image.at<uchar>(r + 1, c - 1);
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    else if( r == rows - 1 && c == cols - 1)
    {
        if(i == 0)
            texture = image.at<uchar>(r - 1, c - 1);
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
        {}
        else if( i == 3)
        {}
        else if( i == 4)
        {}
        else if( i == 5)
        {}
        else if( i == 6)
        {}
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    else if( r == rows - 1 && c > 0 && c < cols - 1)
    {
        if(i == 0)
            texture = image.at<uchar>(r - 1, c - 1);
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
            texture = image.at<uchar>(r - 1, c + 1);
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
        {}
        else if( i == 5)
        {}
        else if( i == 6)
        {}
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    else if( r == rows - 1 && c == 0)
    {
        if(i == 0)
        {}
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
            texture = image.at<uchar>(r - 1, c + 1);
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
        {}
        else if( i == 5)
        {}
        else if( i == 6)
        {}
        else if( i == 7)
        {}
    }
    else if( r > 0 && r < rows - 1 && c == 0)
    {
        if(i == 0)
        {}
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
            texture = image.at<uchar>(r - 1, c + 1);
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
            texture = image.at<uchar>(r + 1, c + 1);
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
        {}
        else if( i == 7)
        {}
    }
    else
    {
        if(i == 0)
            texture = image.at<uchar>(r - 1, c - 1);
        else if( i == 1)
            texture = image.at<uchar>(r - 1, c);
        else if( i == 2)
            texture = image.at<uchar>(r - 1, c + 1);
        else if( i == 3)
            texture = image.at<uchar>(r, c + 1);
        else if( i == 4)
            texture = image.at<uchar>(r + 1, c + 1);
        else if( i == 5)
            texture = image.at<uchar>(r + 1, c);
        else if( i == 6)
            texture = image.at<uchar>(r + 1, c - 1);
        else if( i == 7)
            texture = image.at<uchar>(r, c - 1);
    }
    return texture;
}

/**
 * @brief uniform_pattern: 3x3 LBP , (P,R) = (8,1)
 * @param image : gray scale
 * @param lbp : gray scale
 */
void uniform_pattern(const cv::Mat &image, cv::Mat &lbp_image)
{
    std::vector<uchar> texture(8);
    std::vector<uchar> signed_texture(8);
    lbp_image = cv::Mat::zeros(image.size(), CV_8UC1);
    int rows = image.rows;
    int cols = image.cols;
    int lbp = 0;
    for(int r = 0; r < image.rows; r++)
    {
        for(int c = 0; c < image.cols; c++)
        {
            lbp = 0;
            for(int i = 0; i < 8; i++)
            {
                texture[i] = get_texture(image, rows, cols, r, c, i);
                // signed / thresholded texture
                if((int)texture[i] - (int)image.at<uchar>(r, c) >= 0)
                {
                    signed_texture[i] = (uchar)1;
                }
                else
                {
                    signed_texture[i] = (uchar)0;
                }
            }

            int changes = 0;
            for(int i = 0; i < 7; i++)
            {
                if(signed_texture[i] != signed_texture[i+1])
                {
                    changes++;
                }
            }
            if(changes <= 2)
            {
                for(int i = 0; i < 8; i++)
                {
                    lbp += (int)signed_texture[i];
                }
            }
            else
            {
                lbp = 9;    // P+1
            }

            lbp_image.at<uchar>(r,c) = (uchar)lbp;
//            printf("(r,c,lbp) = (%d, %d, %d)\n", r, c, lbp);
        }
    }
}

/**
 * @brief uniform_pattern_histogram : 3x3 LBP(1,8)
 * @param lbp_image : gray scale
 * @param hist : 10 bins
 */
void uniform_pattern_histogram(const cv::Mat& image, cv::Mat &norm_lbp_hist)
{
    cv::Mat lbp_image;

    uniform_pattern(image, lbp_image);

    // Uniform Pattern LBP(1,8), bins = 10
    cv::Mat lbp_hist = cv::Mat::zeros(1, 10, CV_32SC1);

    for(int r = 0; r < lbp_image.rows; r++)
    {
        for(int c = 0; c < lbp_image.cols; c++)
        {
            int bin = (int)lbp_image.at<uchar>(r,c);
            lbp_hist.at<int>(0, bin) = lbp_hist.at<int>(0, bin) + 1;
        }
    }

//    cout << lbp_hist << endl;

    norm_lbp_hist = cv::Mat::zeros(1, 10, CV_32FC1);


    for(int c = 0; c < norm_lbp_hist.cols; ++c)
    {
        norm_lbp_hist.at<float>(0, c) = lbp_hist.at<int>(0, c) / (image.rows * image.cols * 1.0);
    }

}


void LBP(const cv::Mat& image, cv::Mat& lbp_image)
{
    lbp_image = cv::Mat::zeros(image.rows-2, image.cols-2, CV_8UC1);
    for(int i=1;i<image.rows-1;i++)
    {
        for(int j=1;j<image.cols-1;j++)
        {
            uchar center = image.at<uchar>(i,j);
            unsigned char code = 0;
            code |= (image.at<uchar>(i-1,j-1) > center) << 7;
            code |= (image.at<uchar>(i-1,j) > center) << 6;
            code |= (image.at<uchar>(i-1,j+1) > center) << 5;
            code |= (image.at<uchar>(i,j+1) > center) << 4;
            code |= (image.at<uchar>(i+1,j+1) > center) << 3;
            code |= (image.at<uchar>(i+1,j) > center) << 2;
            code |= (image.at<uchar>(i+1,j-1) > center) << 1;
            code |= (image.at<uchar>(i,j-1) > center) << 0;
            lbp_image.at<unsigned char>(i-1,j-1) = code;
        }
    }
}
