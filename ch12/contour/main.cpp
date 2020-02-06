#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include <vector>
#include <ctime>

using namespace cv;
using namespace std;

void contours_basic();

int main(){
    contours_basic();
    return 0;
}

void contours_basic(){
    Mat src = imread("../../assets/images/contours.bmp", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    vector<vector<Point>> contours;
    findContours(src, contours, RETR_LIST, CHAIN_APPROX_NONE);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    srand((unsigned int)time(0));
    for(int i = 0; i < contours.size(); i++){
        Scalar c(rand() & 255, rand() & 255, rand() & 255);
        drawContours(dst, contours, i, c, 2);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
