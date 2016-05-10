#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
	double alpha = 0.5;
	double beta	;
	double input;

	Mat img, new_img;

	std::cout<<"Basic  Linear Transform"<<std::endl;
	std::cout<<"----------------------"<<std::endl;
	std::cout<<"Enter alpha [0-3]: ";
	std::cin>>alpha;
	std::cout<<"Enter beta  [0-100]: ";
	std::cin>>beta;


	img = imread("/home/neo/image/shayaga3.jpg", CV_LOAD_IMAGE_COLOR);
	new_img = Mat::zeros(img.size(), img.type());


	for(int y = 0; y < img.rows; y++)
	{
		for(int x = 0; x < img.cols; x++)
		{
			for(int c = 0; c < 3; c++)
			{
				new_img.at<Vec3b>(y, x)[c] = 
					saturate_cast<uchar>(alpha*(img.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	imshow("Original Image", img);
	imshow("New Image", new_img);

	waitKey(0);
	return 0;
}

