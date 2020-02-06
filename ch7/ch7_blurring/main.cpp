#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void blurring_mean(){
    Mat src = imread("../../assets/images/rose.bmp", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    namedWindow("src");
    imshow("src", src);

    Mat dst;
    for(int ksize = 3; ksize <= 7; ksize += 2){
        blur(src, dst, Size(ksize, ksize));

        String desc = format("Mean: %dx%d", ksize, ksize);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);

        namedWindow("dst");
        imshow("dst", dst);
        waitKey();
    }
    destroyAllWindows();
}

int main(){
    blurring_mean();
    return 0;
}
