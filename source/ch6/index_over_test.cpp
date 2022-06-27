#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {

	int data[] = {
		1,2,3,
		4,5,6,
		7,8,9,
	};

	Mat m1(3, 3, CV_32S, data);

	cout << m1.at<int>(3, 1) << endl << endl;

	return 0;
}