#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void effective_contrast(){
    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load Failed!" << endl;
        return;
    }

    float alpha = 1.f;
    Mat dst = src + (src - 128) * alpha;

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}

int main(){
    effective_contrast();
    return 0;
}
