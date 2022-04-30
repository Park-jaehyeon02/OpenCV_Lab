#include <iostream>
#include <opencv2/opencv.hpp>
#include <time.h>

using namespace std;
using namespace cv;

int main() {
	vector<double> v1, v2;
	v1.reserve(10000000);

	double start_time = clock();
	for (int i = 0; i < v1.capacity(); i++) {
		v1.push_back(i);
	}
	printf("v1.reserve() 사용 % 5.2fms \n", (clock() - start_time));
	cout << v1.capacity() << endl;

	start_time = clock();
	for (int i = 0; i < v1.capacity(); i++) {
		v2.push_back(i);
	}
	printf("reserve 미사용 % 5.2fms \n", (clock() - start_time));
	cout << v2.capacity() << endl;

	return 0;
}