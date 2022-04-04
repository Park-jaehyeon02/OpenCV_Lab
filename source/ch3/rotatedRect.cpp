#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat image(300, 500, CV_8UC1, Scalar(500));	//��� ����
	Point2f center(250, 150), pts[4];
	Size2f size(300, 100);
	RotatedRect rot_rect(center, size, 20);	//ȸ���簢�� ����

	Rect bound_rect = rot_rect.boundingRect();
	rectangle(image, bound_rect, Scalar(0), 1);	//�簢�� �׸���
	circle(image, rot_rect.center, 1, Scalar(0), 2);	//�� �׸���

	rot_rect.points(pts);	//ȸ���簢�� ������ ��ȯ
	for (int i = 0; i < 4; i++)
	{
		circle(image, pts[i], 4, Scalar(0), 1);	// ������ ǥ��
		line(image, pts[i], pts[(i + 1) % 4], Scalar(0), i+1);	// ������ �մ� ���� ;(i+4) % 4 �� 0~3������ ����Ʈ�� �ձ� ���� ������
	}

	imshow("ȸ���簢��", image);
	waitKey(0);

	return 0;
}