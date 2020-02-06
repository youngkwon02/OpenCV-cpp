#include <iostream>
#include </usr/local/include/opencv4/opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#include "./affine_transform.cpp"
#include "./affine_translation.cpp"
#include "./affine_shear.cpp"
#include "./affine_scale.cpp"
#include "./affine_rotation.cpp"
#include "./affine_flip.cpp"

int main(){
    affine_transform();
    affine_translation();
    affine_shear();
    affine_scale();
    affine_rotation();
    affine_flip();
    return 0;
}
