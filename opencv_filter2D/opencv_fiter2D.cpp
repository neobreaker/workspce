#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

int main(int argc, char** argv)
{
	Mat src, dst;

	Mat kernel;
	Point anchor;
	double delta;
	int ddepth;
	int kernel_size;
	char* window_name = "filter2D Demo";

	int c;

	src = imread("/home/neo/image/shayaga03.jpg");

	if(!src.data)
	{
		return -1;
	}

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	int idx = 0;
	while(1)
	{
		c = waitKey(500);
		if((char)c == 27)	//esc
		{
			break;
		}
		kernel_size = 3+2*(idx%5);
		kernel = Mat::ones(kernel_size, kernel_size, CV_32F)/(float)(kernel_size * kernel_size);
		filter2D(src, dst,ddepth, kernel, anchor, delta, BORDER_DEFAULT);
		imshow(window_name, dst);
		idx++;
	}
	return 0;

}

