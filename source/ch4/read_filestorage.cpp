#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	FileStorage fs("test.xml", FileStorage::READ);
	CV_Assert(fs.isOpened());
	
	string name, university, picture;
	int age;
	fs["university"] >> university;
	fs["name"] >> name;
	fs["age"] >> age;
	cout << "university " << university << endl;
	cout << "name " << name << endl;
	cout << "age " << age << endl;

	// 콜렉션 노드 가져오기
	FileNode node_pic = fs["picture"];
	FileNode node_hd = fs["hardware"];

	try {
		if (node_pic.type() != FileNode::SEQ) CV_Error(Error::StsError, "시퀀스 노드가 아닙니다.");
		if (!node_hd.isMap()) CV_Error(Error::StsError, "맵핑 노드가 아닙니다.");
	}
	catch (Exception& e) {
		cout << "Exit" << endl;
		exit(1);
	}

	cout << "[picture]  ";
	cout << (string)node_pic[0] << ", ";
	cout << (string)node_pic[1] << ", ";
	cout << (string)node_pic[2] << endl << endl;

	Point pt;
	Rect rect;
	Mat mat;
	vector<float> vec;
	
	fs["vector"] >> vec;
	fs["Point"] >> pt;
	fs["Rect"] >> rect;
	fs["Mat"] >> mat;

	cout << "[Vec] = " << ((Mat)vec).t() << endl;
	cout << "[pt] = " << pt << endl;
	cout << "[rect] = " << rect << endl << endl;
	cout << "[mat] = " << endl << mat << endl;

	fs.release();
	return 0;
}