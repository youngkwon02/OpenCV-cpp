#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void hough_lines(){

    Mat src = imread("../../assets/images/building.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat edge;
    Canny(src, edge, 50, 150);

    vector<Vec2f> lines;
    HoughLines(edge, lines, 1, CV_PI / 180, 250);

    Mat dst;
    cvtColor(edge, dst, COLOR_GRAY2BGR);

    for(size_t i = 0; i < lines.size(); i++){
        float r = lines[i][0], t = lines[i][1];
        double cos_t = cos(t), sin_t = sin(t);
        double x0 = r * cos_t, y0 = r * sin_t;
        double alpha = 1000;

        Point pt1(cvRound(x0 + alpha * (-sin_t)), cvRound(y0 + alpha * cos_t));
        Point pt2(cvRound(x0 - alpha * (-sin_t)), cvRound(y0 - alpha * cos_t));
        line(dst, pt1, pt2, Scalar(0, 0, 255), 2, LINE_AA);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destroyAllWindows();
}

void hough_line_segments(){
    Mat src = imread("../../assets/images/building.jpg", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat edge;
    Canny(src, edge, 50, 150);

    vector<Vec4i> lines;
    HoughLinesP(edge, lines, 1, CV_PI/180, 160, 50, 5);

    Mat dst;
    cvtColor(edge, dst, COLOR_GRAY2BGR);

    for(Vec4i l : lines){
        line(dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255),
                2, LINE_AA);
    }

    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);
    destroyAllWindows();
}

void hough_circles(){
    Mat src = imread("../../assets/images/coins.png", IMREAD_GRAYSCALE);

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat blurred;
    blur(src, blurred, Size(3, 3));

    vector<Vec3f> circles;
    HoughCircles(blurred, circles, HOUGH_GRADIENT, 1, 50, 150, 30);

    Mat dst;
    cvtColor(src, dst, COLOR_GRAY2BGR);

    for(Vec3f c : circles){
        Point center(cvRound(c[0]), cvRound(c[1]));
        int radius = cvRound(c[2]);
        circle(dst, center, radius, Scalar(0, 0, 255), 2, LINE_AA);
    }

    imshow("src", src);
    imshow("blurred", blurred);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}

int main(){
    hough_lines();
    hough_line_segments();
    hough_circles();
    return 0;
}
