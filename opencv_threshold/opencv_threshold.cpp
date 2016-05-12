#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int threshold_value = 0;
int threshold_type = 3;
const int max_value = 255;
const int max_type = 4;
const int max_BINARY_value = 255;

Mat src, src_gary, dst;
char* window_name = "Threshold Demo";

char* trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";

char* trackbar_value = "Value";

void ThreholdDemo(int , void *)
{
	threshold(src_gary, dst, threshold_value, max_BINARY_value,
			threshold_type);
	imshow(window_name, dst);
}

int main(int argc, char** argv)
{

	src = imread("/home/neo/image/shayaga03.jpg", 1);

	cvtColor(src, src_gary, CV_RGB2GRAY);

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	createTrackbar(trackbar_type, window_name, &threshold_type,
			max_type, ThreholdDemo);

	createTrackbar(trackbar_value, window_name, & threshold_value,
			max_value, ThreholdDemo);

	ThreholdDemo(0, 0);


	waitKey(0);
	return 0;
}


