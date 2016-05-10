#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

static void help()
{
    cout
        << "\n--------------------------------------------------------------------------" << endl
        << "This program shows how to scan image objects in OpenCV (cv::Mat). As use case"
        << " we take an input image and divide the native color palette (255) with the "  << endl
        << "input. Shows C operator[] method, iterators and at function for on-the-fly item address calculation."<< endl
        << "Usage:"                                                                       << endl
        << "./howToScanImages imageNameToUse divideWith [G]"                              << endl
        << "if you add a G parameter the image is processed in gray scale"                << endl
        << "--------------------------------------------------------------------------"   << endl
        << endl;
}


using namespace cv;

int main(int argc, char** argv)
{
	double alpha = 0.5;
	double beta	;
	double input;

	Mat src1, src2, dst;

	std::cout<<"Simple Linear Blender"<<std::endl;
	std::cout<<"----------------------"<<std::endl;
	std::cout<<"Enter alpha [0-1]: ";
	std::cin>>input;

	if(input >= 0.0 && input <= 1.0)
	{
		alpha = input;
	}

	src1 = imread("/home/neo/image/shayaga3.jpg", CV_LOAD_IMAGE_COLOR);
	src2 = imread("/home/neo/image/shayaga4.jpg", CV_LOAD_IMAGE_COLOR);

	if(!src1.data)
	{
		std::cout<<"Error loading src1\n";
		return -1;
	}
	
	if(!src2.data)
	{
		std::cout<<"Error loading src2n";
		return -1;
	}

	namedWindow("Linear Blend", 1);
	beta = (1 - alpha);
	addWeighted(src1, alpha, src2, beta, 0.0, dst);

	imshow("Linear Blend", dst);

	waitKey(0);
	return 0;
}

