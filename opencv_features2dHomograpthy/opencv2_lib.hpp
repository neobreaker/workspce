#ifndef __OPENCV2_LIB_HPP__
#define __OPENCV2_LIB_HPP__

#include <stdio.h>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/xfeatures2d.hpp>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

//version 1.0

namespace cvlib
{

class CvLib
{
public :

	static void SURFDetectAndCampute(const Mat& img, 
			std::vector<KeyPoint>& keypoints,
			Mat& descriptor)
	{
		int minHessian = 400;

		Ptr<SURF> detector = SURF::create(minHessian);
		detector->detectAndCompute(img, Mat(),
				keypoints,
				descriptor);
	}

	static void BFGoodMatch(const Mat& descriptor_object, 
				const Mat& descriptor_scene,
				std::vector<DMatch>& good_matches)
	{
		BFMatcher matcher(NORM_L2);

		std::vector<DMatch> matches;
		matcher.match(descriptor_object, 
				descriptor_scene, matches);

		double max_dist = 0;
		double min_dist = 100;

		for(int i = 0; i < descriptor_object.rows; i++)
		{
			double dist = matches[i].distance;
			if(dist < min_dist)
				min_dist = dist;
			if(dist > max_dist)
				max_dist = dist;
		}

		cout<<"--Max dist :"<<max_dist<<endl
			<<"--Min dist :"<<min_dist<<endl;

		for(int i = 0; i < descriptor_object.rows; i++)
		{
			if(matches[i].distance <= 3*min_dist)
			{
				good_matches.push_back(matches[i]);
			}
		}

	}
	
	static void FlannBaseGoodMatch(const Mat& descriptor_object, 
				const Mat& descriptor_scene,
				std::vector<DMatch>& good_matches)
	{

		FlannBasedMatcher matcher;

		std::vector<DMatch> matches;
		matcher.match(descriptor_object, 
				descriptor_scene, matches);

		double max_dist = 0;
		double min_dist = 100;

		for(int i = 0; i < descriptor_object.rows; i++)
		{
			double dist = matches[i].distance;
			if(dist < min_dist)
				min_dist = dist;
			if(dist > max_dist)
				max_dist = dist;
		}

		cout<<"--Max dist :"<<max_dist<<endl
			<<"--Min dist :"<<min_dist<<endl;

		for(int i = 0; i < descriptor_object.rows; i++)
		{
			if(matches[i].distance <= 3*min_dist)
			{
				good_matches.push_back(matches[i]);
			}
		}
	}

	static void DrawMatch(const Mat& img_object, 
			Mat& img_matches, 
			const std::vector<KeyPoint>& keypoints_object, 
			const std::vector<KeyPoint>& keypoints_scene, 
			const std::vector<DMatch>& matches)
	{

		std::vector<Point2f> obj;
		std::vector<Point2f> scene;

		for(size_t i = 0; i < matches.size(); i++)
		{
			obj.push_back(keypoints_object[matches[i].queryIdx].pt);
			scene.push_back(keypoints_scene[matches[i].trainIdx].pt);
		}

		Mat H = findHomography(obj, scene, RANSAC);
		std::vector<Point2f> obj_corners(4);
		obj_corners[0] = cvPoint(0, 0);
		obj_corners[1] = cvPoint(img_object.cols, 0);
		obj_corners[2] = cvPoint(img_object.cols, img_object.rows);
		obj_corners[3] = cvPoint(0, img_object.rows);

		std::vector<Point2f> scene_corners(4);

		perspectiveTransform(obj_corners, scene_corners, H);

		line( img_matches, 
			scene_corners[0],// + Point2f( img_object.cols, 0), 
			scene_corners[1],// + Point2f( img_object.cols, 0), 
			Scalar(0, 255, 0), 4 );
		line( img_matches, 
			scene_corners[1],//+ Point2f( img_object.cols, 0), 
			scene_corners[2],// + Point2f( img_object.cols, 0), 
			Scalar(0, 255, 0), 4 );
		line( img_matches, 
			scene_corners[2],// + Point2f( img_object.cols, 0), 
			scene_corners[3],// + Point2f( img_object.cols, 0), 
			Scalar(0, 255, 0), 4 );
		line( img_matches, 
			scene_corners[3],// + Point2f( img_object.cols, 0), 
			scene_corners[0],// + Point2f( img_object.cols, 0), 
			Scalar(0, 255, 0), 4 );
	}


};

}


#endif

