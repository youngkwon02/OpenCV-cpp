#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace std;
using namespace cv;

Mat img;
Point ptOld;
void on_mouse(int event, int x, int y, int flags, void*);

int main(){
    img = imread("../../assets/images/lena.jpg");

    if(img.empty()){
        cerr << "Image load failed" << endl;
        return -1;
    }

    namedWindow("img");
    setMouseCallback("img", on_mouse);

    imshow("img", img);
    waitKey(0);

    return 0;
}

void on_mouse(int event, int x, int y, int flags, void*){
    switch(event){
        case EVENT_LBUTTONDOWN:
            ptOld = Point(x, y);
            cout << "EVENT_LBUTTONDOWN: " << x << ", " << y << endl;
            break;
        
        case EVENT_LBUTTONUP:
            cout << "EVENT_LBUTTONUP: " << x << ", " << y << endl;
            break;

        case EVENT_MOUSEMOVE:
            if(flags & EVENT_FLAG_LBUTTON) {
                line(img, ptOld, Point(x, y), Scalar(0, 255, 255), 2);
                imshow("img", img);
                // Update ptOld here!
                ptOld = Point(x, y);
            }
            break;
        default:
            break;
    }
}
