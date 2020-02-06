#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void on_trackbar(int pos, void* userdata);

int main(){
    Mat src = imread("../../assets/images/sudoku.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed\n";
        return -1;
    }

    imshow("src", src);

    namedWindow("dst");
    createTrackbar("Block Size", "dst", 0, 200, on_trackbar, (void*)&src);
    setTrackbarPos("Block Size", "dst", 11);

    waitKey(0);
    return 0;
}

void on_trackbar(int pos, void* userdata){
    Mat src = *(Mat*)userdata;

    int bsize = pos;
    if(bsize % 2 == 0)
        bsize--;
    if(bsize < 3)
        bsize = 3;

    Mat dst;
    adaptiveThreshold(src, dst, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY,
            bsize, 5);

    imshow("dst", dst);
}
