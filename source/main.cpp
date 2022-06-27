#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

// 히스토그램 계산해주는 함수
void calc_Histo(Mat image, Mat& hist, int bins, int range_max = 256)
{
    int histSize[] = { bins };               // 히스토그램 계급 개수
    float range[] = { 0, (float)range_max };   // 0번 채널 화소값 범위
    int channels[] = { 0 };                  // 채널 목록 - 단일 채널
    const float* ranges[] = { range };         // 모든 채널 화소 범위

    // openCV:: 내장 히스토그램 계산 함수
    calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
}

// 히스토그램 그려주는 함수
void draw_histo(Mat hist, Mat& hist_img, Size size = Size(256, 256))
{
    hist_img = Mat(size, CV_8U, Scalar(255));      // 그래프 행렬
    float bin = (float)hist_img.cols / hist.rows;   // 한 계급 너비
    normalize(hist, hist, 0, hist_img.rows, NORM_MINMAX);

    for (int i = 0; i < hist.rows; i++)
    {
        float start_x = i * bin;         // 막대 사각형 시작 x 좌표
        float end_x = (i + 1) * bin;      // 막대 사각형 종료 x 좌표
        Point2f pt1(start_x, 0);
        Point2f pt2(end_x, hist.at<float>(i));

        if (pt2.y > 0) rectangle(hist_img, pt1, pt2, Scalar(0), -1);   // 막대 사각형 그리기
    }
    flip(hist_img, hist_img, 0);   // x축 기준 영상 뒤집기
}

void create_hist(Mat img, Mat& hist, Mat& hist_img)
{
    int histsize = 256, range = 256;
    calc_Histo(img, hist, histsize, range);      // 히스토그램 계산
    draw_histo(hist, hist_img);               // 히스토그램 그래프 그리기
}

int main()
{
    Mat image = imread("../image/rainbow_cat.jpg", IMREAD_GRAYSCALE);   // 명암도 영상 읽기
    CV_Assert(!image.empty());                                 // 영상파일 예외처리
    Mat hist, dst1, dst2, hist_img, hist_img1, hist_img2;
    create_hist(image, hist, hist_img);         // 히스토그램 및 그래프 그리기

    // 히스토그램 누적 합 계산
    Mat accum_hist = Mat(hist.size(), hist.type(), Scalar(0));
    accum_hist.at<float>(0) = hist.at<float>(0);
    for (int i = 1; i < hist.rows; i++)
    {
        accum_hist.at<float>(i) = hist.at<float>(i - 1) + hist.at<float>(i);
    }

    accum_hist /= sum(hist)[0];      // 누적합의 정규화
    accum_hist *= 255;

    dst1 = Mat(image.size(), CV_8U);
    for (int i = 0; i < image.rows; i++) {
        for (int j = 0; j < image.cols; j++)
        {
            int idx = image.at<uchar>(i, j);
            dst1.at<uchar>(i, j) = (uchar)accum_hist.at<float>(idx);
        }
    }

    // normalize(accum_hist, accum_hist, 0, 255, NORM_MINMAX);      // 누적합의 정규화
    //accum_hist.convertTo(accum_hist, CV_8U);
    //LUT(image, accum_hist, dst1);                           // 룩업 테이블 적용

    equalizeHist(image, dst2);            // OpenCV 히스토그램 평활화
    create_hist(dst1, hist, hist_img1);      // 히스토그램 및 그래프 그리기
    create_hist(dst2, hist, hist_img2);

    imshow("image", image);            // 원본 히스토그램
    imshow("img_hist", hist_img);
    imshow("dst1-User", dst1);         // 사용자 평활화
    imshow("User_hist", hist_img1);
    imshow("dst2-OpenCV", dst2);      // OpenCV 평활화
    imshow("OpenCV_hist", hist_img2);
    waitKey(0);
    return 0;
}