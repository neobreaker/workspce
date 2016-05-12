#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

Mat src, dst;
int borderType;
Scalar value;
char* window_name = "copyMakeBorder Demo";
RNG rng(12345);

void help()
{
	cout<<"\n \t copyMakeBorder Demo: \n"
		<<"\t -------------------- \n"
		<<" ** Press 'c' to set the border to a random constant value \n"
		<<" ** Press 'r' to set the border to be replicated \n"
		<<" ** Press 'ESC' to exit the program \n";
}

int main(int argc, char** argv)
{
	help();
	
	int top, bottom, left, right;
	int c;
	src = imread("/home/neo/image/shayaga03.jpg");
	if(!src.data)
	{
		cout<<"Load image Error\n";
		return -1;
	}

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	
	top = (int)(0.05*src.rows);
	bottom = (int)(0.05*src.rows);
	left  = (int) (0.05*src.cols);
	right = (int)(0.05*src.cols);
	dst = src;

	imshow(window_name, dst);

	while(1)
	{
		c = waitKey(500);
		if((char)c == 27)
		{
			break;
		}
		else if((char)c == 'c')
		{
			borderType = BORDER_CONSTANT;
		}
		else if((char)c == 'r')
		{
			borderType = BORDER_REPLICATE;
		}
		value = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), 
				rng.uniform(0, 255));
		copyMakeBorder(src, dst, top, bottom, left, right,
				borderType, value);
		imshow(window_name, dst);
	}

	return 0;
}

