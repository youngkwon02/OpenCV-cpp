#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void on_level_change(int pos, void* userdata);

int main(void){
    Mat img = Mat :: zeros(400, 400, CV_8UC1);

    namedWindow("image");
    createTrackbar("level", "image", 0, 16, on_level_change, (void*)&img);
    imshow("image", img);
    waitKey(0);

    return 0;
}

void on_level_change(int pos, void* userdata){
    Mat img = *(Mat*)userdata;

    img.setTo(pos * 16);
    imshow("image", img);
}
