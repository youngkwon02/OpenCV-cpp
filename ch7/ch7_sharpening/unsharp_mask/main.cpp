#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void unsharp_mask(){
    Mat src = imread("../../../assets/images/rose.bmp", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load Failed!" << endl;
        return;
    }

    namedWindow("src");
    imshow("src", src);

    for(int sigma=1; sigma <= 5; sigma++){
        Mat blurred;
        GaussianBlur(src, blurred, Size(), sigma);

        float alpha = 1.f;
        Mat dst = (1 + alpha) * src - alpha * blurred;

        String desc = format("sigma: %d", sigma);
        putText(dst, desc, Point(10, 50), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255), 1, LINE_AA);

        imshow("dst", dst);
        waitKey();
    }

    destroyAllWindows();
}

int main(){
    unsharp_mask();
    return 0;
}
