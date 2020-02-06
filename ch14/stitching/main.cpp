#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    if(argc < 3){
        cerr << "Usage: stitching.exe <image_file1> <image_file2> [<image_file3>...]" << endl;
        return -1;
    }

    vector<Mat> imgs;
    for(int i = 1; i < argc; i++){
        Mat img = imread(argv[i]);

        if(img.empty()){
            cerr << "Image load failed!\n";
            return -1;
        }

        imgs.push_back(img);
    }

    Ptr<Stitcher> stitcher = Stitcher::create();

    Mat dst;
    Stitcher::Status status = stitcher->stitch(imgs, dst);

    if(status != Stitcher::Status::OK){
        cerr << "Error on stitching\n";
        return -1;
    }

    imwrite("result.jpg", dst);

    imshow("dst", dst);

    waitKey();
    return 0;
}
