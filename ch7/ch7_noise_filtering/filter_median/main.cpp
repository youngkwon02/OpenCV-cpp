#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void filter_median(){
    Mat src = imread("../../../assets/images/lena.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    int num = (int)(src.total() * 0.1);
    for(int i=0; i<num; i++){
        int x = rand() % src.cols;
        int y = rand() % src.rows;
        src.at<uchar>(y, x) = (i % 2) * 255;
    }

    Mat dst1;
    GaussianBlur(src, dst1, Size(), 1);

    Mat dst2;
    medianBlur(src, dst2, 3);

    namedWindow("src");
    imshow("src", src);

    namedWindow("dst1");
    imshow("dst1", dst1);

    namedWindow("dst2");
    imshow("dst2", dst2);

    waitKey();
    destroyAllWindows();
}

int main(){
    filter_median();
    return 0;
}
