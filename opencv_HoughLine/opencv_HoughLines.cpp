#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

Mat src, edges;
Mat src_gray;
Mat standard_hough, probablilistic_hough;
int min_threshold = 50;
int max_trackbar  = 150;

const char* standard_name = "Standard Hough Lines Demo";
const char* probablilistic_name = "Probabililistic Hough Lines demo";

int s_trackbar = max_trackbar;
int p_trackbar = max_trackbar;

void help()
{
	cout<<"\t Hough Transform to detect lines \n "
		<<"\t---------------------------------\n "
		<<" Usage: ./HoughLines_Demo <image_name> \n";
}

void StandardHough(int , void*)
{
	vector<Vec2f> slines;
	cvtColor(edges, standard_hough, COLOR_GRAY2BGR);

	HoughLines(edges, slines, 1, CV_PI/180, min_threshold + s_trackbar, 0, 0);

	for(size_t i = 0; i < slines.size(); i++)
	{
		float r = slines[i][0], t = slines[i][1];
		double cos_t = cos(t), sin_t = sin(t);
		double x0 = r*cos_t, y0 = r*sin_t;
		double alpha = 1000;

		Point pt1(cvRound(x0 + alpha*(-sin_t)), 
				cvRound(y0 + alpha*cos_t));
		Point pt2(cvRound(x0 - alpha*(-sin_t)),
				cvRound(y0 - alpha*cos_t));
		line(standard_hough, pt1, pt2, Scalar(255,0,0), 3, LINE_AA);
	}

	imshow(standard_name, standard_hough);
}

void Probalilistic_Hough(int , void *)
{
	vector<Vec4i> plines;
	cvtColor(edges, probablilistic_hough, COLOR_GRAY2BGR);
	
	HoughLinesP(edges, plines, 1,
			CV_PI/180, min_threshold+p_trackbar, 50, 10);

	for(size_t i = 0; i < plines.size(); i++)
	{
		Vec4i l = plines[i];
		line(probablilistic_hough, 
				Point(l[0], l[1]),
				Point(l[2], l[3]),
				Scalar(255,0,0),
				3, LINE_AA);
	}
	imshow(probablilistic_name, probablilistic_hough);
}

int main(int argc, char** argv)
{
	
	src = imread("/home/neo/image/Hough_Lines_Tutorial_Original_Image.jpg");
	if(!src.data)
	{
		return -1;
	}

	cvtColor(src, src_gray, COLOR_RGB2GRAY);

	Canny(src_gray, edges, 50, 200, 3);

	char threshold_label[50];
	sprintf(threshold_label, "Thres:%d + input", min_threshold);

	namedWindow(standard_name, WINDOW_AUTOSIZE);
	createTrackbar(threshold_label, standard_name,
			&s_trackbar, max_trackbar, StandardHough);


	namedWindow(probablilistic_name, WINDOW_AUTOSIZE);
	createTrackbar(threshold_label, probablilistic_name,
			&p_trackbar, max_trackbar, Probalilistic_Hough);

	StandardHough(0,0);
	Probalilistic_Hough(0, 0);
	waitKey(0);
	return 0;
}


