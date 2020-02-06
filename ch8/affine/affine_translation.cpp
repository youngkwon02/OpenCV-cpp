void affine_translation(){
    Mat src = imread("../../assets/images/tekapo.bmp");

    if(src.empty()){
        cerr << "Image load failed!" << endl;
        return;
    }

    Mat M = Mat_<double>({ 2, 3 }, { 1, 0, 150, 0, 1, 100 });
    Mat dst;
    warpAffine(src, dst, M, Size());

    namedWindow("src");
    imshow("src", src);
    namedWindow("dst");
    imshow("dst", dst);

    waitKey();
    destroyAllWindows();
}
