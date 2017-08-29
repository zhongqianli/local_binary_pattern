#include <iostream>
#include <vector>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void LBP(const Mat& src, Mat& dst)
{
    dst = Mat::zeros(src.rows-2, src.cols-2, CV_8UC1);
    for(int i=1;i<src.rows-1;i++)
    {
        for(int j=1;j<src.cols-1;j++)
        {
            uchar center = src.at<uchar>(i,j);
            unsigned char code = 0;
            code |= (src.at<uchar>(i-1,j-1) > center) << 7;
            code |= (src.at<uchar>(i-1,j) > center) << 6;
            code |= (src.at<uchar>(i-1,j+1) > center) << 5;
            code |= (src.at<uchar>(i,j+1) > center) << 4;
            code |= (src.at<uchar>(i+1,j+1) > center) << 3;
            code |= (src.at<uchar>(i+1,j) > center) << 2;
            code |= (src.at<uchar>(i+1,j-1) > center) << 1;
            code |= (src.at<uchar>(i,j-1) > center) << 0;
            dst.at<unsigned char>(i-1,j-1) = code;
        }
    }
}

//vector<int> convertToBinary(int x)
//{
//    vector<int> result(8, 0);
//    int idx = 0;

//    while(x != 0) {
//        result[idx] = x % 2;
//        ++idx;
//        x /= 2;
//    }
//    reverse(result.begin(), result.end());
//    return result;
//}

//int countTransitions(vector<int> x)
//{
//    int result = 0;
//    for(int i = 0; i < 8; ++i)
//        result += (x[i] != x[(i+1) % 8]);
//    return result;
//}

//Mat uniformPatternHistogram(const Mat& src, int numPatterns)
//{
//    Mat hist;
//    hist = Mat::zeros(1, (numPatterns + 1), CV_32SC1);
//    for(int i = 0; i < numPatterns; ++i) {
//        if(countTransitions(convertToBinary(i)) > 2)
//            hist.at<int>(0, i) = -1;
//    }
//    for(int i = 0; i < src.rows; i++)
//    {
//        for(int j = 0; j < src.cols; j++)
//        {
//            int bin = (int)src.at<uchar>(i,j);
//            if(hist.at<int>(0, bin) == -1)
//                hist.at<int>(0, numPatterns) += 1;
//            else
//                hist.at<int>(0,bin) += 1;
//        }
//    }
//    return hist;
//}

//void uniformPatternSpatialHistogram(const Mat& src, Mat& hist, int
//                                    numPatterns, const Size& window, int overlap)
//{
//    int width = src.cols;
//    int height = src.rows;
//    vector<Mat> histograms;
//    for(int x=0; x <= (width - window.width); x+=(window.width-overlap))
//    {
//        for(int y=0; y <= (height-window.height); y+=(window.height - overlap))
//        {
//            Mat cell = Mat(src, Rect(x,y,window.width, window.height));
//            histograms.push_back(uniformPatternHistogram(cell,
//                                                         numPatterns));
//        }
//    }
//    hist.create(1, histograms.size()*(numPatterns+1), CV_32SC1);
//    for(int histIdx=0; histIdx < histograms.size(); histIdx++) {
//        for(int valIdx = 0; valIdx < (numPatterns+1); valIdx++) {
//            int y = (histIdx * (numPatterns+1)) + valIdx;
//            hist.at<int>(0,y) = histograms[histIdx].at<int>(valIdx);
//        }
//    }
//}

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
            texture = image.at<uchar>(r - 1, c - 1);
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
void uniform_pattern_histogram(const cv::Mat& lbp_image, cv::Mat &hist)
{
    // Uniform Pattern LBP(1,8), bins = 10
    hist = cv::Mat::zeros(1, 10, CV_32SC1);

    for(int r = 0; r < lbp_image.rows; r++)
    {
        for(int c = 0; c < lbp_image.cols; c++)
        {
            int bin = (int)lbp_image.at<uchar>(r,c);
            hist.at<int>(0, bin) = hist.at<int>(0, bin) + 1;
        }
    }
}

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

    Mat src = imread(filename, CV_LOAD_IMAGE_GRAYSCALE);

    if(src.empty())
    {
        cout << "no image" << endl;
        return -1;
    }

    Mat lbp_img;
    LBP(src, lbp_img);

    std::cout << src.size() << endl;

    imshow("lbp", lbp_img);


    int bt = cv::getTickCount();
    uniform_pattern(src, lbp_img);
    int et = cv::getTickCount();
    double t = (et - bt)*1000.0 / cv::getTickFrequency();
    printf("t = %f\n", t);

    imshow("uniform lbp", lbp_img/10.0*255.0);

    Mat lbp_hist;
    uniform_pattern_histogram(lbp_img, lbp_hist);
    cout << lbp_hist << endl;

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

