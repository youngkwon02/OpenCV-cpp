#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include <ctime>

using namespace cv;
using namespace std;

void corner_fast();

int main()
{
    corner_fast();
    return 0;
}

void corner_fast()
{
    Mat src = imread("../../assets/images/building.jpg", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    vector<KeyPoint> keypoints;
    FAST(src, keypoints, 60, true);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    srand((unsigned int)time(0));
    for(KeyPoint kp : keypoints){
        Point pt(cvRound(kp.pt.x), cvRound(kp.pt.y));
        circle(dst, pt, 5, Scalar(rand() % 255, rand() % 255, rand() % 255),
                2);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destroyAllWindows();
}
