#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{
	Mat src, dst;

	src = imread("/home/neo/image/shayaga.jpg", 1);

	if(!src.data)
	{
		cout<< "Load image error\n";
		return -1;
	}
	char* r_window = "Red Channel";
	char* b_window = "Blue Channel";
	char* g_window = "Green Channel";
	vector<Mat> rgb_planes;
	split(src, rgb_planes);

	namedWindow(r_window, CV_WINDOW_AUTOSIZE);
	namedWindow(g_window, CV_WINDOW_AUTOSIZE);
	namedWindow(b_window, CV_WINDOW_AUTOSIZE);
	imshow(r_window, rgb_planes[0]);
	imshow(g_window, rgb_planes[1]);
	imshow(b_window, rgb_planes[2]);

	int histSize = 255;

	float range[] = {0, 255};
	const float* histRange = {range};
	bool uniform = true, accumulate = false;

	Mat r_hist, g_hist, b_hist;

	calcHist(&rgb_planes[0], 1, 0, Mat(), r_hist, 1, &histSize, &histRange,
			uniform, accumulate);
	calcHist(&rgb_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange,
			uniform, accumulate);
	calcHist(&rgb_planes[2], 1, 0, Mat(), b_hist, 1, &histSize, &histRange,
			uniform, accumulate);

	int hist_w = 400, hist_h = 400;
	int bin_w = cvRound((double) hist_w/histSize);	

	Mat histImage(hist_w, hist_h, CV_8UC3, Scalar(0,0,0));

	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for(int i = 0; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i-1), hist_h-cvRound(r_hist.at<float>(i-1))),
				Point(bin_w*i, hist_h-cvRound(r_hist.at<float>(i))),
				Scalar(0,0,255), 2, 8, 0);
		line(histImage, Point(bin_w*(i-1), hist_h-cvRound(g_hist.at<float>(i-1))),
				Point(bin_w*i, hist_h-cvRound(g_hist.at<float>(i))),
				Scalar(0,255,0), 2, 8, 0);
		line(histImage, Point(bin_w*(i-1), hist_h-cvRound(b_hist.at<float>(i-1))),
				Point(bin_w*i, hist_h-cvRound(b_hist.at<float>(i))),
				Scalar(255,0,0), 2, 8, 0);
	}

	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
	imshow("calcHist Demo", histImage);

	waitKey(0);
	return 0;
}

