#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void corner_harris();

int main()
{
    corner_harris();
    return 0;
}

void corner_harris(){
    Mat src = imread("../../assets/images/building.jpg", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    Mat harris;
    cornerHarris(src, harris, 3, 3, 0.04);

    Mat harris_norm;
    normalize(harris, harris_norm, 0, 255, NORM_MINMAX, CV_8U);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for(int j = 1; j < harris.rows - 1; j++){
        for(int i = 1; i < harris.cols - 1; i++){
            if(harris_norm.at<uchar>(j, i) > 120){
                if(harris.at<float>(j, i) > harris.at<float>(j - 1, i) &&
                   harris.at<float>(j, i) > harris.at<float>(j + 1, i) &&
                   harris.at<float>(j, i) > harris.at<float>(j, i - 1) &&
                   harris.at<float>(j, i) > harris.at<float>(j, i + 1) ){
                    circle(dst, Point(i, j), 5, Scalar(0, 0, 255), 2);
                }
            }
        }
    }

    while(true){
        imshow("src", src);
        imshow("harris_norm", harris_norm);
        imshow("dst", dst);
        
        if(waitKey(1) == 27){
            break;
        }
    }
}
