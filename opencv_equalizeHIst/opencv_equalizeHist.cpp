#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main()
{

	Mat src, dst;

	char* src_window = "Source image";
	char* equalized_window = "Equalized Image";

	src = imread("/home/neo/image/shayaga.jpg", 1);

	if(!src.data)
	{
		cout<< "Load image error\n";
		return -1;
	}

	cvtColor(src, src, CV_BGR2GRAY);

	equalizeHist(src, dst);

	namedWindow(src_window, CV_WINDOW_AUTOSIZE);
	namedWindow(equalized_window, CV_WINDOW_AUTOSIZE);

	imshow(src_window, src);
	imshow(equalized_window, dst);

	waitKey(0);
	return 0;
}

