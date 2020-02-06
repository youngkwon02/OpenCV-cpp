#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include <vector>
#include <ctime>

using namespace cv;
using namespace std;

void contours_hier();

int main(){
    contours_hier();
    return 0;
}

void contours_hier(){
    Mat src = imread("../../assets/images/contours.bmp", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(src, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    srand((unsigned int)time(0));
    for(int idx = 0; idx >= 0; idx = hierarchy[idx][0]) {
        Scalar c(rand() & 255, rand() & 255, rand() & 255);
        drawContours(dst, contours, idx, c, -1, LINE_8, hierarchy);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
