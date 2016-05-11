#include "opencv2/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

const int DELAY_CAPTION = 1500;
const int DELAY_BLUR = 100;
const int MAX_KERNEL_LENGTH = 31;

Mat src;
Mat dst;

char window_name[] = "Filter Demo 1";

int displayCaption(char* caption)
{
	dst = Mat::zeros(src.size(), src.type());

	putText(dst, caption, Point(src.cols/4, src.rows/2),
			CV_FONT_HERSHEY_COMPLEX, 1, Scalar(255,255,255));
	imshow(window_name, dst);
	int c = waitKey(DELAY_CAPTION);
	if(c >= 0)
		return -1;
	return 0;
}

int displayDst(int delay)
{
	imshow(window_name, dst);
	int c = waitKey(DELAY_CAPTION);
	if(c >= 0)
		return -1;
	return 0;
}
int main(int argc, char** argv)
{
	namedWindow(window_name, CV_WINDOW_AUTOSIZE);

	src = imread("/home/neo/image/shayaga.jpg", 1);
	if(displayCaption("Original Image") != 0)	
		return 0;

	dst = src.clone();
	if(displayDst(DELAY_CAPTION) != 0)
		return 0;

	if(displayCaption("Homogeneous Blur") != 0)	
		return 0;

	for(int i = 1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		blur(src, dst, Size(i, i), Point(-1, -1));
		if(displayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}
	
	if(displayCaption("Gaussian Blur") != 0)	
		return 0;

	for(int i = 1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		GaussianBlur(src, dst, Size(i, i), 0, 0);
		if(displayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}

	if(displayCaption("Median Blur") != 0)	
		return 0;

	for(int i = 1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		medianBlur(src, dst, i);
		if(displayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}
	
	if(displayCaption("Bilateral Blur") != 0)	
		return 0;

	for(int i = 1; i < MAX_KERNEL_LENGTH; i+=2)
	{
		bilateralFilter(src, dst, i, i*2, i/2);
		if(displayDst(DELAY_BLUR)!=0)
		{
			return 0;
		}
	}
	
	waitKey(0);
	return 0;
}

