#include <iostream>
#include <cv.h>
using namespace std;
using namespace cv;
int main(int argc, char** argv)
{

	Mat M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << "M = " << endl << " " << M << endl << endl;
	return 0;
}
