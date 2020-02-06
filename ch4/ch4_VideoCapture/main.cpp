#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void video_in(){
    VideoCapture cap("../../assets/video/spiderman.mp4");
    if(!cap.isOpened()){
        cerr << "Video open failed!" << endl;
        return;
    }
    
    cout << "Frame Width : " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame Height : " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    cout << "Frame Count : " << cvRound(cap.get(CAP_PROP_FRAME_COUNT)) << endl;

    double fps = cap.get(CAP_PROP_FRAME_COUNT);
    cout << "FPS : " << fps << endl;

    int delay = cvRound(1000 / fps);
    
    Mat frame, inversed;
    while(true){
        cap >> frame;
        if(frame.empty()){
            break;
        }

        inversed = ~frame;

        imshow("frame", frame);
        imshow("inversed", inversed);

        if(waitKey(delay) == 27){ //ESC Key
            break;
        }

        destroyAllWindows();

    }
}

int main(){
    video_in();
    cout << "All Processes Done!" << endl;
    return 0;
}
