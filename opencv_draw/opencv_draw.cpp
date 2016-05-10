#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#define W 400

using namespace cv;

void MyEllipse(Mat img, double angle)
{
	int thickness = 2;
	int lineType = 8;

	ellipse(img,
			Point(W/2.0, W/2.0),
			Size(W/4.0, W/16.0),
			angle,
			0,
			360,
			Scalar(255, 0, 0),
			thickness,
			lineType);
}

void MyFilledCirlle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
			center,
			W/32,
			Scalar(0,0,255),
			thickness,
			lineType);
}

void MyPolygon(Mat img)
{
	int lineType = 8;

	Point rook_points[1][20];
	rook_points[0][0] = Point(W/4, 7*W/8);
	rook_points[0][1] = Point(3*W/4, 7*W/8);
	rook_points[0][2] = Point(3*W/4, 13*W/16);
	rook_points[0][3] = Point(11*W/16, 13*W/16);
	rook_points[0][4] = Point(19*W/32, 3*W/8);
	rook_points[0][5] = Point(3*W/4, 3*W/8);
	rook_points[0][6] = Point(3*W/4, W/8);
	rook_points[0][7] = Point(26*W/40, W/8);
	rook_points[0][8] = Point(26*W/40, W/4);
	rook_points[0][9] = Point(22*W/40, W/4);
	rook_points[0][10] = Point(22*W/40, W/8);
	rook_points[0][11] = Point(18*W/40, W/8);
	rook_points[0][12] = Point(18*W/40, W/4);
	rook_points[0][13] = Point(14*W/40, W/4);
	rook_points[0][14] = Point(14*W/40, W/8);
	rook_points[0][15] = Point(W/4, W/8);
	rook_points[0][16] = Point(W/4, 3*W/8);
	rook_points[0][17] = Point(13*W/32, 3*W/8);
	rook_points[0][18] = Point(5*W/16, 13*W/16);
	rook_points[0][19] = Point(W/4, 13*W/16);

	const Point *ppt[1] = {rook_points[0]};
	int npt[] = {20};

	fillPoly(img,
			ppt,
			npt,
			1,
			Scalar(255, 255, 255),
			lineType);
}

void MyLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;

	line(img,
		start,
		end,
		Scalar(0,0,0),
		thickness,
		lineType);
}

int main(int argc, char** argv)
{
	char atom_window[] = "Drawing 1: Atom";
	char rook_windw[]  = "Drawing 2: Rook";

	Mat atom_image = Mat::zeros(W, W, CV_8UC3);
	Mat rook_image = Mat::zeros(W, W, CV_8UC3);

	MyEllipse(atom_image, 90);
	MyEllipse(atom_image, 0);
	MyEllipse(atom_image, 45);
	MyEllipse(atom_image, -45);

	MyFilledCirlle(atom_image, Point(W/2, W/2));


	MyPolygon(rook_image);

	rectangle(rook_image,
			Point(0, 7*W/8),
			Point(W, W),
			Scalar(0, 255, 255),
			-1,
			8);

	MyLine(rook_image, Point(0, 15*W/16), Point(W, 15*W/16));
	MyLine(rook_image, Point(W/4, 7*W/8), Point(W/4, W));
	MyLine(rook_image, Point(W/2, 7*W/8), Point(W/2, W));
	MyLine(rook_image, Point(3*W/4, 7*W/8), Point(3*W/4, W));

	imshow(atom_window, atom_image);
	moveWindow(atom_window, 0, 200);
	imshow(rook_windw, rook_image);
	moveWindow(rook_windw, W, 200);
	
	waitKey(0);
	return 0;
}


