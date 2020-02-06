#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img){
    CV_Assert(img.type() == CV_8UC1);

    Mat hist;
    int channels[] = { 0 };
    int dims = 1;
    const int histSize[] = { 256 };
    float graylevel[] = { 0, 256 };
    const float* ranges[] = { graylevel };

    calcHist(&img, 1, channels, noArray(), hist, dims, histSize, ranges);

    return hist;
}

Mat getGrayHistImage(const Mat& hist){
    CV_Assert(hist.type() == CV_32FC1);
    CV_Assert(hist.size() == Size(1, 256));

    double histMax;
    minMaxLoc(hist, 0, &histMax);

    Mat imgHist(100, 256, CV_8UC1, Scalar(255));
    for(int i = 0; i < 256; i++){
        line(imgHist, Point(i, 100),
                Point(i, 100 - cvRound(hist.at<float>(i, 0)*100/histMax)), Scalar(0));
    }
    return imgHist;
}

int main(){
    Mat src = imread("../../assets/images/camera.bmp", IMREAD_GRAYSCALE);
    Mat histArr = calcGrayHist(src);
    Mat histImg = getGrayHistImage(histArr);
    namedWindow("src");
    namedWindow("srcHist");
    imshow("src", src);
    imshow("srcHist", histImg);
    waitKey();
    return 0;
}
