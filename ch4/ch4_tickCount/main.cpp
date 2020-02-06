#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void time_inverse(){
    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst(src.rows, src.cols, src.type());

    TickMeter tm;
    tm.start();

    for(int j=0; j<src.rows; j++){
        for(int i=0; i<src.cols; i++){
            dst.at<uchar>(j, i) = 255 - src.at<uchar>(j, i);
        }
    }

    tm.stop();
    cout << "Image inverse took " << tm.getTimeMilli() << "ms." << endl;
}

int main(){
    time_inverse();
    return 0;
}
