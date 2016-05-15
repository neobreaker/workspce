#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace cv::xfeatures2d;

int main()
{
	Mat img_1 = imread("/home/neo/image/hana.png", 1);
	Mat img_2 = imread("/home/neo/image/shayaga03.jpg");
	

	int minHessian = 400;

	Ptr<SURF> detector = SURF::create();
	detector->setHessianThreshold(minHessian);

	std::vector<KeyPoint> keypoint_1, keypoint_2;
	Mat descriptors_1, descriptors_2;

	detector->detectAndCompute(img_1, Mat(),
			keypoint_1, descriptors_1);
	detector->detectAndCompute(img_2, Mat(),
			keypoint_2, descriptors_2);

	BFMatcher matcher(NORM_L2);
	std::vector<DMatch> matches;
	matcher.match(descriptors_1, descriptors_2, matches);	
		
	Mat img_matches;
	drawMatches(img_1, keypoint_1, img_2, keypoint_2,
			matches, img_matches);

	imshow("Matches", img_matches);
	waitKey(0);
	return 0;
}

