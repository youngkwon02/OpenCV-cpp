#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    cout << "Hello OpenCV " << CV_VERSION << endl;
    
    Mat img;
    img = imread("lena.jpg");

    if(img.empty()){
        cerr << "Image load failed!" << endl;
        return -1;
    }

    namedWindow("image");
    imshow("image", img);

    waitKey(0);
    return 0;
}

