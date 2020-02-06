void affine_flip(){
    Mat src = imread("../../assets/images/eastsea.bmp");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    namedWindow("src");
    imshow("src", src);

    Mat dst;
    int flipCode[] = { 1, 0, -1 };
    for(int i = 0; i < 3; i++){
        flip(src, dst, flipCode[i]);

        String desc = format("flipCode: %d", flipCode[i]);
        putText(dst, desc, Point(10, 30), FONT_HERSHEY_SIMPLEX, 1.0,
                Scalar(255, 0, 0), 1, LINE_AA);

        namedWindow("dst");
        imshow("dst", dst);
        waitKey();
    }
    destroyAllWindows();
}
