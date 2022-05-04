#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	Range r1(0, 3), r2(3, 7);
	int data[] = {
		10,11,12,13,14,15,16,
		20,21,22,23,24,25,26,
		30,31,32,33,34,35,36,
		40,41,42,43,44,45,46,
	};

	Mat m1, m2;
	m1 = Mat(4, 7, CV_32S, data);	// 4행, 7열 행렬선언 및 초기화
	m2 = m1(r1, r2);	// 범위 객체로 관심영역  참조

	cout << "[m1의 2번 행] =" << m1.row(2) << endl;
	cout << "[m1의 1번 열] =" << m1.col(1) << endl;
	cout << "[m1의 (0~2)행 모두] =" << m1.rowRange(r1) << endl << endl;

	cout << "[m1] =" << endl << m1 << endl << endl;
	cout << "[m2 (0~2행 3~6열) 참조] =" << endl << m2 << endl << endl;

	m2.setTo(50);
	cout << "[m2] =" << endl << m2 << endl;
	cout << "[m1] =" << endl << m1 << endl << endl;

	return 0;
}