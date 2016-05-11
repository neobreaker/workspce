#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

Mat src, dst, tmp;
char* window_name = "Gaussian Pyramids Demo";

void help()
{
	cout<<"Zoom IN-Out demo    \n"
		<<"--------------------\n"
		<<"[u] -- Zoom in\n"
		<<"[d] -- Zoom Out\n"
		<<"[Esc] -- Exit the program"<<endl;
}


int main(int argc, char** argv)
{
	help();
	src = imread("/home/neo/image/shayaga.jpg");
	if(!src.data)
	{
		cout<<"Load src error"<<endl;
		return -1;
	}

	tmp = src;
	dst = tmp;

	namedWindow(window_name, CV_WINDOW_AUTOSIZE);
	imshow(window_name, dst);

	while(true)
	{
		int c;
		c = waitKey(10);

		if((char)c == 27)
		{
			break;
		}
		else if((char)c == 'u')
		{
			pyrUp(tmp, dst, Size(tmp.cols*2, tmp.rows*2));
		}
		else if((char)c == 'd')
		{
			pyrDown(tmp, dst, Size(tmp.cols/2, tmp.rows/2));
		}
		imshow(window_name, dst);
		tmp = dst;
	}


}

