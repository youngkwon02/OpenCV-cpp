#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void color_split(){
    Mat src = imread("../../assets/images/candies.png");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    vector<Mat> bgr_planes;
    split(src, bgr_planes);

    imshow("src", src);
    imshow("B_plane", bgr_planes[0]);
    imshow("G_plane", bgr_planes[1]);
    imshow("R_plane", bgr_planes[2]);

    waitKey();
    destroyAllWindows();
}

int main(){
    color_split();
    return 0;
}
