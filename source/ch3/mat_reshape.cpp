#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

void print_matInfo(string m_name, Mat m)	// 채널 정보 출력
{
	cout << "[" << m_name << "행렬]" << endl;
	cout << "		채널 수 = " << m.channels() << endl;
	cout << "		행 x 열 = " << m.rows << " x " << m.cols << endl << endl;
}

int main() {
	Mat m1(2, 6, CV_8U);
	Mat m2 = m1.reshape(2);		// 2채널 행렬로 변경 생성
	Mat m3 = m1.reshape(3, 2);		// 3체날, 2헹 헹렬로 변경 생성

	print_matInfo("m1(2,6)", m1);
	print_matInfo("m2 = m1_reshape(2)", m2);
	print_matInfo("m3 = m1_reshape(3,2)", m3);

	m1.create(3, 5, CV_16S);
	print_matInfo("	m1.create(3, 5, CV_16S)", m1);

	return 0;
}