#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

string face_cascade_name = "/home/neo/package/opencv-3.1.0/data/haarcascades/haarcascade_frontalface_alt.xml";
string eyes_cascade_name = "/home/neo/package/opencv-3.1.0/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
string window_name = "face detect demo";
RNG rng(12345);

void DetectFace(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, CV_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );

	for(int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x+faces[i].width*0.5,
				faces[i].y+faces[i].height*0.5);
		ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5),
				0,0,360, Scalar(255, 0, 255), 4, 8, 0);
		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 
				0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
		for(int j = 0; j < eyes.size(); j++)
		{
			Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5,
					faces[i].y + eyes[j].y + eyes[j].height*0.5);
			int radius = cvRound( (eyes[j].width+eyes[j].height)*0.25);
			circle(frame, center, radius, Scalar(255,0,0), 4, 8, 0);
		}
	}
}

int main()
{
	CvCapture* capture;

	if(!face_cascade.load(face_cascade_name))
	{
		cout<<"Load face_cascade error\n";
		return -1;
	}
	if(!eyes_cascade.load(eyes_cascade_name))
	{
		cout<<"Load eyes_cascade error\n";
	}

	Mat face_img = imread("/home/neo/image/shayaga2.jpg", 1);
	DetectFace(face_img);

	imshow(window_name, face_img);


	waitKey(0);
	return 0;
}



