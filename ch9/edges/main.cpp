#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void sobel_edge(){

    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dx, dy;
    Sobel(src, dx, CV_32FC1, 1, 0);
    Sobel(src, dy, CV_32FC1, 0, 1);

    Mat fmag, mag;
    magnitude(dx, dy, fmag);
    fmag.convertTo(mag, CV_8UC1);

    Mat edge = mag > 150;

    imshow("src", src);
    imshow("mag", mag);
    imshow("edge", edge);

    waitKey();
    destroyAllWindows();
}

void canny_edge(){
    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst1, dst2;
    Canny(src, dst1, 50, 100);
    Canny(src, dst2, 50, 100);

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}

int main(){
    sobel_edge();
    canny_edge();
    return 0;
}
