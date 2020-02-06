#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void detect_keypoints();

int main()
{
    detect_keypoints();
    return 0;
}

void detect_keypoints()
{
    Mat src = imread("../../assets/images/box_in_scene.png", IMREAD_GRAYSCALE);
    if(src.empty()){
        cerr << "Image load failed!\n";
        return;
    }

    Ptr<Feature2D> feature = ORB::create();

    vector<KeyPoint> keypoints;
    feature->detect(src, keypoints);

    Mat desc;
    feature->compute(src, keypoints, desc);

    cout << "keypoints.size(): " << keypoints.size() << "\n";
    cout << "desc.size(): " << desc.size() << "\n";

    Mat dst;
    drawKeypoints(src, keypoints, dst, Scalar::all(-1),
            DrawMatchesFlags::DRAW_RICH_KEYPOINTS);


    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
