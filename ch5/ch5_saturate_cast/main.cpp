#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void brightness(){
    Mat src = imread("../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst(src.rows, src.cols, src.type());

    for(int j=0; j<src.rows; j++){
        for(int i=0; i<src.cols; i++){
            dst.at<uchar>(j, i) = saturate_cast<uchar>(src.at<uchar>(j, i)+100);
        }
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}

int main(){
    brightness();
    return 0;
}
