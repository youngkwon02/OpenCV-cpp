#include</usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;

int main(){
    Mat src1 = imread("../../assets/images/airplane.bmp", IMREAD_GRAYSCALE);
    Mat src2 = imread("../../assets/images/field.bmp", IMREAD_GRAYSCALE);

    Mat dst;
    absdiff(src1, src2, dst);

    namedWindow("src1");
    imshow("src1", src1);
    namedWindow("src2");
    imshow("src2", src2);
    namedWindow("dst");
    imshow("dst", dst);
    waitKey();
    destroyAllWindows();

    return 0;

}
