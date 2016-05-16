#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "./opencv2_lib.hpp"

using namespace cvlib;
using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

int main()
{

	Mat img_object = imread("/home/neo/image/shayagaface01.png",
			IMREAD_GRAYSCALE);
	Mat img_scene = imread("/home/neo/image/shayaga02.jpg",
			IMREAD_GRAYSCALE);
	Mat img_scene_src = imread("/home/neo/image/shayaga02.jpg",1);

	std::vector<KeyPoint> keypoints_object, keypoint_scene;
	Mat descriptor_object, descriptor_scene;
	
	CvLib::SURFDetectAndCampute(img_object, keypoints_object,
			descriptor_object);
	CvLib::SURFDetectAndCampute(img_scene, keypoint_scene,
			descriptor_scene);
	std::vector<DMatch> good_matches;

//	CvLib::BFGoodMatch(descriptor_object, descriptor_scene,
//			good_matches);

	CvLib::FlannBaseGoodMatch(descriptor_object, descriptor_scene,
			good_matches);

	Mat img_matches;
	drawMatches(img_object, keypoints_object,
			img_scene, keypoint_scene,
			good_matches, img_matches, Scalar::all(-1),
			Scalar::all(-1),
			std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		CvLib::DrawMatch(img_object, img_scene_src, keypoints_object,
				keypoint_scene, good_matches);
		imshow("Good Matches & Object detection", img_matches);
		imshow("Scene", img_scene_src);

	waitKey(0);
	return 0;
}


