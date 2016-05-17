#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char** argv)
{

	Mat img;
	img = imread("/home/neo/image/shayaga01.jpg", cv::IMREAD_COLOR);

	cout<<"Size(): "<<img.size()<<endl;

	imshow("Read Img demo", img);

	waitKey(0);
	return 0;
}



