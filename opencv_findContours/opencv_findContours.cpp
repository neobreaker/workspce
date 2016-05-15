#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat src, src_gray;
int thresh = 100;
int max_length = 255;
RNG rng(12345);

void ThreshCallback(int , void *)
{
	Mat canny_output;
	vector<vector<Point> > contours;
	vector<Vec4i> hierarchy;

	Canny(src_gray, canny_output, thresh, thresh*2, 3);

	findContours(canny_output, contours, hierarchy, CV_RETR_TREE, 
			CV_CHAIN_APPROX_SIMPLE, Point(0,0));

	Mat drawing = Mat::zeros(canny_output.size(),
			CV_8UC3);
	for(int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255),
				rng.uniform(0, 255),
				rng.uniform(0, 255));
		drawContours(drawing, contours, i,
				color, 2, 8, hierarchy, 0, Point());
	}
	namedWindow("Contours", CV_WINDOW_AUTOSIZE);
	imshow("Contours", drawing);
}

int main()
{
//	src = imread("/home/neo/image/Find_Contours_Original_Image.jpg", 1);
	src = imread("/home/neo/image/shayaga03.jpg");

	cvtColor(src, src_gray, CV_BGR2GRAY);
	blur(src_gray, src_gray, Size(3,3));

	char* source_window = "Source";
	namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	imshow(source_window, src);

	createTrackbar("Canny thresh:", "Source", &thresh, max_length, ThreshCallback);

	ThreshCallback(0, 0);

	waitKey(0);
	return 0;
}


