#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include <iostream>

Point ptPrev(-1, -1);

void on_mouse(int event, int x, int y, int flags, void* userdata)
{
    Mat img = *(Mat*)userdata;;

    if(event == EVENT_LBUTTONDOWN){
        ptPrev = Point(x, y);
    }else if(event == EVENT_LBUTTONUP){
        ptPrev = Point(-1, -1);
    }else if(event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON)){
        line(img, ptPrev, Point(x, y), Scalar::all(255), 40, LINE_AA, 0);
        ptPrev = Point(x, y);

        imshow("img", img);
    }
}
