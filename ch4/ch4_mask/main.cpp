#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void mask_copyTo(){
    Mat src = imread("../../assets/images/airplane.bmp", IMREAD_COLOR);
    Mat mask = imread("../../assets/images/mask_plane.bmp", IMREAD_COLOR);
    Mat dst = imread("../../assets/images/field.bmp", IMREAD_COLOR);

    if(src.empty() || mask.empty() || dst.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    src.copyTo(dst, mask);

    imshow("dst", dst);
    waitKey(0);
    destroyAllWindows();
}

int main(){
    mask_copyTo();
    return 0;
}
