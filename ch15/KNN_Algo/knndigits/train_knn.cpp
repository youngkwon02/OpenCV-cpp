#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include <iostream>

Ptr<KNearest> train_knn()
{
    Mat digits = imread("../../../assets/images/digits.png", IMREAD_GRAYSCALE);

    if(digits.empty()){
        cerr << "Image load failed!\n";
        return 0;
    }

    Mat train_images, train_labels;

    for(int j = 0; j < 50; j++){
        for(int i = 0; i < 100; i++){
            Mat roi, roi_float, roi_flatten;
            roi = digits(Rect(i * 20, j * 20, 20, 20));
            roi.convertTo(roi_float, CV_32F);
            roi_flatten = roi_float.reshape(1, 1);

            train_images.push_back(roi_flatten);
            train_labels.push_back(j / 5);
        }
    }

    Ptr<KNearest> knn = KNearest::create();
    knn->train(train_images, ROW_SAMPLE, train_labels);

    return knn;
}
