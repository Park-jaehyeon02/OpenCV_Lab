#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;


int main(int ac, char** av) {

	Mat img = imread("./resource/Lenna.png");

	imshow("img", img);
	waitKey(0);

	return 0;
}