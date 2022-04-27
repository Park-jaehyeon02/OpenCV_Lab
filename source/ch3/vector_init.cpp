#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main() {
	vector<Point> v1;	//�� ���� ����
	v1.push_back(Point(10, 20));	//���Ϳ� ���� �߰�
	v1.push_back(Point(20, 30));
	v1.push_back(Point(50, 60));

	vector<float> v2(3, 9.25);	//float�� ���� ���� �� �ʱ�ȭ
	Size arr_size[] = { Size(2,2),Size(3,3) ,Size(4,4) };
	int arr_int[] = { 10,20,30,40,50 };

	// �迭���ҷ� ���� �ʱ�ȭ
	vector<Size> v3(arr_size, arr_size + sizeof(arr_size) / sizeof(Size));	//Size�� �迭 ����
	vector<Size> v4(arr_int+2, arr_int + sizeof(arr_int) / sizeof(int));	//Size�� �迭 ����

	cout << "[v1] " << (Mat)v1 << endl;	//����ȯ �� ���
	cout << "[v2] " << ((Mat)v2).reshape(1, 1) << endl;
	cout << "[v3] " << ((Mat)v3).reshape(1, 1) << endl;
	cout << "[v4] " << ((Mat)v4).reshape(1, 1) << endl;

	return 0;
}