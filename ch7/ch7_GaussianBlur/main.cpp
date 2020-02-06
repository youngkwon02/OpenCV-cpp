#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void blurring_gaussian(){
    Mat src = imread("../../assets/images/rose.bmp", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    namedWindow("src");
    imshow("src", src);

    Mat dst;
    for(int sigma = 1; sigma <= 5; sigma++){
        GaussianBlur(src, dst, Size(), (double)sigma);

        String text = format("sigma = %d", sigma);
        putText(dst, text, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0, Scalar(255), 1, LINE_AA);
        imshow("dst", dst);
        waitKey();
    }
    destroyAllWindows();
}

int main(){
    blurring_gaussian();
    return 0;
}
