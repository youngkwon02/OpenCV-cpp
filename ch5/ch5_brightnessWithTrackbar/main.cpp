#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void on_brightness(int pos, void* userdata);

void brightness(){
    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load Failed!" << endl;
        return;
    }

    namedWindow("dst");
    createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
    on_brightness(0, (void*)&src);

    waitKey();
    destroyAllWindows();
}

void on_brightness(int pos, void* userdata){
    Mat src = *(Mat*)userdata;
    Mat dst = src + pos;

    imshow("dst", dst);
}

int main(){
    brightness();
    return 0;
}
