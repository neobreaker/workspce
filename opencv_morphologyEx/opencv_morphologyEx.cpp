#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace cv;

Mat src, dst;

int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
const int max_operation = 4;
const int max_elem = 2;
const int max_kernel = 21;

char* window_name = "Morphlogy Transformations Demo";

void morphologyOperation(int, void*)
{
	int operation = morph_operator +2;
	Mat elem  = getStructuringElement(morph_elem, 
			Size(2*morph_size+1, 2*morph_size+1), 
			Point(morph_size, morph_size));

	morphologyEx(src, dst, operation, elem);
	imshow(window_name, dst);
}

int main(int argc, char** argv)
{
	src = imread("/home/neo/image/shayaga.jpg");
	if(!src.data)
	{
		return -1;
	}

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	createTrackbar("Operator:\n0:Opening - 1:Closing\n 2:Gradient -3:Top Hat\n \
			4:Black Hat", window_name,
			&morph_operator, max_operation, morphologyOperation);

	createTrackbar("Element:\n0:Rect - 1:Cross - 2:Ellipse", window_name,
			&morph_elem, max_elem, morphologyOperation);

	createTrackbar("Kernel size:\n 2n+1", window_name,
			&morph_size, max_kernel, morphologyOperation);

	morphologyOperation(0, 0);

	waitKey(0);
	return 0;
}

