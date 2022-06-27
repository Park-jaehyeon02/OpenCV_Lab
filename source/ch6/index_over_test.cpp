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
	Point pt(1, 0);

	cout << m1.at<int>(1,0)<< endl << endl;

	return 0;
}