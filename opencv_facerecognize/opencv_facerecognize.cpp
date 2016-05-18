#include "../opencv2_lib.hpp"
using namespace cvlib;

const char* FACEOBJWINDOWNAME = "face obj window";
const char* FACESCENEWINDOWNAME = " face scene window";

string face_cascade_name = "/home/neo/package/opencv-3.1.0/data/haarcascades/haarcascade_frontalface_alt.xml";

int main(int argc, char**argv)
{

	Mat face_obj;
	Mat face_scene;
	std::vector<Mat> faces_obj_img;
	std::vector<Mat> face_scene_img;
	CascadeClassifier face_cascade;
	std::vector<KeyPoint> keypoints_object, keypoint_scene;
	Mat descriptor_object, descriptor_scene;

	face_obj  = imread("/home/neo/image/sy_obj02.jpg", 1);
	face_scene = imread("/home/neo/image/sy_obj02.jpg", 1);

	if(!face_obj.data || !face_scene.data)
	{
		cout<<"Load face Failed\n";
		return -1;
	}

	if(!face_cascade.load(face_cascade_name))
	{
		cout<<"Load face_cascade error\n";
		return -1;
	}

	namedWindow(FACEOBJWINDOWNAME, CV_WINDOW_AUTOSIZE);
	namedWindow(FACESCENEWINDOWNAME, CV_HAAR_SCALE_IMAGE);

	CvLib::DetectFace(face_obj, faces_obj_img, face_cascade);

	if(faces_obj_img.size() > 0)
	{
//		CvLib::SURFDrawKeyPoints(faces_obj_img[0]);
//
		std::vector<KeyPoint> keypoints_object, keypoints_scene;
		Mat descriptor_object, descriptor_scene;
	
		CvLib::SURFDetectAndCampute(faces_obj_img[0], 
				keypoints_object,
				descriptor_object);
		CvLib::SURFDetectAndCampute(face_scene, keypoints_scene,
				descriptor_scene);
		std::vector<DMatch> good_matches;

		CvLib::FlannBaseGoodMatch(descriptor_object, 
				descriptor_scene,
				good_matches);

		Mat img_matches;
	/*
		drawMatches(faces_obj_img[0], keypoints_object,
			face_scene, keypoints_scene,
			good_matches, img_matches, Scalar::all(-1),
			Scalar::all(-1),
			std::vector<char>(), 
			DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	*/
		CvLib::DrawMatch(faces_obj_img[0], 
				face_scene, keypoints_object,
				keypoints_scene, good_matches);
		imshow(FACEOBJWINDOWNAME, faces_obj_img[0]);
//		imshow("Match window", img_matches);
		imshow(FACESCENEWINDOWNAME, face_scene);
	}
	else
	{
		cout<<"Detect face in obj Failed\n";
		return -1;
	}

	waitKey(0);
	return 0;
}



