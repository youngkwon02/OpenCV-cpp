void affine_scale(){
    Mat src = imread("../../assets/images/rose.bmp");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat dst1, dst2, dst3, dst4;
    resize(src, dst1, Size(), 4, 4, INTER_NEAREST);
    resize(src, dst2, Size(1920, 1280));
    resize(src, dst3, Size(1920, 1280), 0, 0, INTER_CUBIC);
    resize(src, dst4, Size(1920, 1280), 0, 0, INTER_LANCZOS4);

    namedWindow("src");
    namedWindow("dst1");
    namedWindow("dst2");
    namedWindow("dst3");
    namedWindow("dst4");

    imshow("src", src);
    imshow("dst1", dst1);
    imshow("dst2", dst2);
    imshow("dst3", dst3);
    imshow("dst4", dst4);

    waitKey();
    destroyAllWindows();
}
