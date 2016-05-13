#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

char* source_window = "Source image";
char* wrap_window = "Wrap";
char* wrap_rotate_window = "Wrap + Rotate";

int main()
{
	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat rot_mat(2, 3, CV_32FC1);
	Mat wrap_mat(2, 3, CV_32FC1);
	Mat src, wrap_dst, wrap_rotate_dst;

	src = imread("/home/neo/image/shayaga.jpg", 1);

	wrap_dst = Mat::zeros(src.rows, src.cols, src.type());

	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols-1, 0);
	srcTri[2] = Point2f(0, src.rows -1);

	dstTri[0] = Point2f(src.cols*0.0, src.rows*0.33);
	dstTri[1] = Point2f(src.cols*0.85, src.rows*0.25);
	dstTri[0] = Point2f(src.cols*0.15, src.rows*0.7);

	wrap_mat = getAffineTransform(srcTri, dstTri);
	warpAffine(src, wrap_dst, wrap_mat, wrap_dst.size());

	Point center = Point(wrap_dst.cols/2, wrap_dst.rows/2);
	double angle = -50.0;
	double scale = 0.6;

	rot_mat = getRotationMatrix2D(center, angle, scale);
	warpAffine(wrap_dst, wrap_rotate_dst, rot_mat, wrap_dst.size());

	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);

	namedWindow(wrap_window, CV_WINDOW_AUTOSIZE);
	imshow(wrap_window, wrap_dst);

	namedWindow(wrap_rotate_window, CV_WINDOW_AUTOSIZE);
	imshow(wrap_rotate_window, wrap_rotate_dst);

	waitKey(0);
	return 0;
}

