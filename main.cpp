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

vector<int> convertToBinary(int x)
{
    vector<int> result(8, 0);
    int idx = 0;

    while(x != 0) {
        result[idx] = x % 2;
        ++idx;
        x /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int countTransitions(vector<int> x)
{
    int result = 0;
    for(int i = 0; i < 8; ++i)
        result += (x[i] != x[(i+1) % 8]);
    return result;
}

Mat uniformPatternHistogram(const Mat& src, int numPatterns)
{
    Mat hist;
    hist = Mat::zeros(1, (numPatterns + 1), CV_32SC1);
    for(int i = 0; i < numPatterns; ++i) {
        if(countTransitions(convertToBinary(i)) > 2)
            hist.at<int>(0, i) = -1;
    }
    for(int i = 0; i < src.rows; i++)
    {
        for(int j = 0; j < src.cols; j++)
        {
            int bin = (int)src.at<uchar>(i,j);
            if(hist.at<int>(0, bin) == -1)
                hist.at<int>(0, numPatterns) += 1;
            else
                hist.at<int>(0,bin) += 1;
        }
    }
    return hist;
}

void uniformPatternSpatialHistogram(const Mat& src, Mat& hist, int
                                    numPatterns, const Size& window, int overlap)
{
    int width = src.cols;
    int height = src.rows;
    vector<Mat> histograms;
    for(int x=0; x <= (width - window.width); x+=(window.width-overlap))
    {
        for(int y=0; y <= (height-window.height); y+=(window.height - overlap))
        {
            Mat cell = Mat(src, Rect(x,y,window.width, window.height));
            histograms.push_back(uniformPatternHistogram(cell,
                                                         numPatterns));
        }
    }
    hist.create(1, histograms.size()*(numPatterns+1), CV_32SC1);
    for(int histIdx=0; histIdx < histograms.size(); histIdx++) {
        for(int valIdx = 0; valIdx < (numPatterns+1); valIdx++) {
            int y = (histIdx * (numPatterns+1)) + valIdx;
            hist.at<int>(0,y) = histograms[histIdx].at<int>(valIdx);
        }
    }
}

int main(int argc, char **argv)
{
    //    int uniform_pattern_cnt = 0;
    //    for (int i = 0; i < 256; ++i) {
    //        vector<int> bin_i = convertToBinary(i);
    //        int num_transitions = countTransitions(bin_i);
    //        if (num_transitions <= 2)
    //            uniform_pattern_cnt += 1;
    //    }
    //    cout << "There are " << uniform_pattern_cnt << " 8-bit uniform\
    //            patterns\n";
    //            return 0;

    string imagepath;

    if(argc != 2)
    {
        cout << "USAGE: ./lbp_image [IMAGE]\n";
//        return 1;
        imagepath = "face.bmp";
    }
    else
    {
        imagepath = argv[1];
    }

    Mat src = imread(imagepath, CV_LOAD_IMAGE_GRAYSCALE);

    Mat lbp_img;
    LBP(src, lbp_img);
    imshow("lbp", lbp_img);
    waitKey(0);

    Mat spatial_hist;
    uniformPatternSpatialHistogram(lbp_img, spatial_hist, 256, cv::Size(3,3), 0);

    vector<int> feature_vector;
    for(int j = 0; j < spatial_hist.cols; ++j)
    {
        if(spatial_hist.at<int>(0, j) != -1)
            feature_vector.push_back(spatial_hist.at<int>(0, j));
//        else
//        {
//            cout << "err: -1" << endl;
//        }
    }

    cout << "********" << endl;

    for(int i = 0; i < feature_vector.size(); ++i)

    {
        if(i != (feature_vector.size() - 1))
            cout << feature_vector[i] << " ";
        else
            cout << feature_vector[i];
    }
    cout << "\n";
    return 0;

}

