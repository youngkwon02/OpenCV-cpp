#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void decode_qrcode();

int main()
{
    decode_qrcode();
    return 0;
}

void decode_qrcode()
{
    QRCodeDetector detector;

    Mat frame = imread("../../assets/images/qrcode.png", IMREAD_COLOR);

    while(true){

        if(frame.empty()){
            cerr << "Frame load failed!\n";
            break;
        }

        vector<Point> points;
        String info = detector.detectAndDecode(frame, points);

        if(!info.empty()){
            polylines(frame, points, true, Scalar(0, 0, 255), 2);
            putText(frame, info, Point(10, 30), FONT_HERSHEY_DUPLEX, 1,
                    Scalar(0, 0, 255));
        }

        imshow("frame", frame);
        if(waitKey(1) == 27)
            break;
    }

}
