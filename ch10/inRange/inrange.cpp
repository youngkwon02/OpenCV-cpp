#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int lower_hue = 40, upper_hue = 80;
Mat src, src_hsv, mask;

void on_hue_changed(int, void*);

int main(int argc, char* argv[]){
    src = imread("../../assets/images/candies.png", IMREAD_COLOR);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return -1;
    }

    cvtColor(src, src_hsv, COLOR_BGR2HSV);

    imshow("src", src);

    namedWindow("mask");
    createTrackbar("Lower Hue", "mask", &lower_hue, 179, on_hue_changed);
    createTrackbar("Upper Hue", "mask", &upper_hue, 179, on_hue_changed);
    on_hue_changed(0, 0);

    waitKey(0);
    return 0;
}

void on_hue_changed(int, void*){
    Scalar lowerb(lower_hue, 100, 0); // Each Parameter is H, S, V
    Scalar upperb(upper_hue, 255, 255);
    inRange(src_hsv, lowerb, upperb, mask);

    imshow("mask", mask);
}
