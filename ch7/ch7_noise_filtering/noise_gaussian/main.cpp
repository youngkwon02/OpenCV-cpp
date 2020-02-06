#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void noise_gaussian(){
    Mat src = imread("../../../assets/images/lena.jpg", IMREAD_GRAYSCALE);
    
    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    namedWindow("src");
    imshow("src", src);

    for(int stddev = 10; stddev <= 30; stddev += 10){
        Mat noise(src.size(), CV_32SC1);
        randn(noise, 0, stddev);

        Mat dst;
        add(src, noise, dst, Mat(), CV_8U);

        String desc = format("stddev = %d", stddev);

        putText(dst, desc, Point(10, 50), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255), 1, LINE_AA);
        
        namedWindow("dst");
        imshow("dst", dst);
        waitKey();
    }

    destroyAllWindows();
}

int main(){
    noise_gaussian();
    return 0;
}
