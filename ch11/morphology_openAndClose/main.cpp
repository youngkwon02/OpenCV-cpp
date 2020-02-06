#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void open_close();

int main(){
    open_close();
    return 0;
}

void open_close(){

    Mat src = imread("../../assets/images/milkdrop.bmp", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    Mat bin;
    threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

    Mat dst1, dst2;
    morphologyEx(bin, dst1, MORPH_OPEN, Mat());
    morphologyEx(bin, dst2, MORPH_CLOSE, Mat());

    imshow("src", src);
    imshow("bin", bin);
    imshow("erode", dst1);
    imshow("dilate", dst2);

    waitKey();
    destroyAllWindows();
}
