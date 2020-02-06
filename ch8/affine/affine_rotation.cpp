void affine_rotation(){
    Mat src = imread("../../assets/images/tekapo.bmp");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Point2f cp(src.cols / 2.f, src.rows / 2.f);
    Mat M = getRotationMatrix2D(cp, 20, 1);

    Mat dst;
    warpAffine(src, dst, M, Size());

    namedWindow("src");
    namedWindow("dst");

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
