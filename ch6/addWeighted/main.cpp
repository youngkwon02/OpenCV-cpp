#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat src1 = imread("../../assets/images/airplane.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread("../../assets/images/field.bmp", IMREAD_GRAYSCALE);

    Mat dst;
    addWeighted(src1, 0.7, src2, 0.3, 0, dst);
    
    namedWindow("dst");
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();
    return 0;
}
