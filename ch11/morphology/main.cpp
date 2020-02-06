#include <iostream>
#include <time.h>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void erode_dilate();

int main(){
    erode_dilate();
    return 0;
}

void erode_dilate(){

    Mat src = imread("../../assets/images/milkdrop.bmp", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }
    
    Mat bin;
    threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
    
    Mat dst1, dst2;
    erode(bin, dst1, Mat());
    erode(bin, dst2, Mat());

    imshow("src", src);
    imshow("bin", bin);
    imshow("dst1", dst1);
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}
