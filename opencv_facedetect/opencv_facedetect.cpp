#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

#include "opencv2_lib.hpp"

using namespace cv;
using namespace std;
using namespace cvlib;

string face_cascade_name = "/home/neo/package/opencv-3.1.0/data/haarcascades/haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "/home/neo/package/opencv-3.1.0/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "face detect demo";
RNG rng(12345);


int main(int argc, char** argv)
{
	CvCapture* capture;

	if(argc < 2)
	{
		cout <<"./a.out <img path>"<<endl;
		return -1;
	}


	if(!face_cascade.load(face_cascade_name))
	{
		cout<<"Load face_cascade error\n";
		return -1;
	}
	if(!eyes_cascade.load(eyes_cascade_name))
	{
		cout<<"Load eyes_cascade error\n";
	}

	string img_path(argv[1]);
		
	Mat face_img = imread(img_path, 1);

	if(!face_img.data)
	{
		cout <<"Load img failed"<<endl;
		return -1;
	}

//	DetectFace(face_img);
	CvLib::DrawDetectFaceAndEyes(face_img, face_cascade, eyes_cascade);

	imshow(window_name, face_img);


	waitKey(0);
	return 0;
}



