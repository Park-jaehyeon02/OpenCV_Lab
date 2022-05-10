#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main()
{
	FileStorage fs_r("test.xml", FileStorage::READ);
	CV_Assert(fs_r.isOpened());

	FileNode node_pic = fs_r["picture"];
	return 0;
}