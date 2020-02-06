#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter_bilateral(){
    Mat src = imread("../../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat noise(src.size(), CV_32SC1);
    randn(noise, 0, 5);
    add(src, noise, src, Mat(), CV_8U);

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 5);

    Mat dst2;
    bilateralFilter(src, dst2, -1, 10, 5);

    namedWindow("src");
    namedWindow("dst1");
    namedWindow("dst2");

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}

int main(){
    filter_bilateral();
    return 0;
}
