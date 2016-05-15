#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

int main()
{

	Mat src = imread("/home/neo/image/shayaga03.jpg");

	int minHessian = 400;
	Ptr<SURF> detector = SURF::create(minHessian);
	
	vector<KeyPoint> keypoint;
	detector->detect(src, keypoint);

	Mat img_keypoint;

	drawKeypoints(src, keypoint, img_keypoint, 
			Scalar::all(-1), DrawMatchesFlags::DEFAULT);

	imshow("KeyPoint", img_keypoint);

	waitKey(0);
	return 0;
}


