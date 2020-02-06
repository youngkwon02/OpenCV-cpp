void affine_shear(){
    Mat src = imread("../../assets/images/tekapo.bmp");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    double mx = 0.3;
    Mat M = Mat_<double>({ 2, 3 }, { 1, mx, 0, 0, 1, 0 });

    Mat dst;
    warpAffine(src, dst, M, Size(cvRound(src.cols + src.rows * mx), src.rows));

    namedWindow("src");
    namedWindow("dst");

    imshow("src", src);
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
