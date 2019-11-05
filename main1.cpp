#include<iostream>
#include<Eigen/Dense>
#include<opencv2/core/core.hpp>
#include<opencv.hpp>
#include<opencv2/core/eigen.hpp>


#define MATRIX1 	A1 <<\
273, 639, 1,\
253, 549, 1,\
263, 449, 1,\
343, 459, 1,\
353, 589, 1,\
363, 719, 1,\
303, 459, 1,\
323, 279, 1,\
323, 279, 1,\
323, 199, 1,\
233, 319, 1,\
183, 339, 1,\
263, 279, 1,\
373, 289, 1,\
423, 379, 1,\
413, 409, 1;

#define MATRIX2 	A2 <<\
273, 639, 1,\
253, 549, 1,\
263, 449, 1,\
343, 459, 1,\
353, 589, 1,\
363, 719, 1,\
303, 459, 1,\
323, 279, 1,\
323, 279, 1,\
323, 199, 1,\
233, 319, 1,\
183, 339, 1,\
263, 279, 1,\
373, 289, 1,\
423, 379, 1,\
413, 409, 1;

#define VECTOR1 	B1 <<\
259,\
240,\
249,\
326,\
345,\
345,\
288,\
288,\
288,\
288,\
192,\
192,\
211,\
345,\
383,\
354;

#define VECTOR2 	B2 <<\
754,\
640,\
516,\
516,\
631,\
754,\
516,\
336,\
307,\
241,\
459,\
412,\
336,\
336,\
421,\
440;

using namespace std;
using namespace Eigen;
using namespace cv;

int main()
{
	MatrixXd A1(16,3);
	MatrixXd A2(16,3);
	VectorXd B1(16);
	VectorXd B2(16);
	MATRIX1;
	VECTOR1;
	//cout << A1 << endl;
	//cout << B1 << endl;
	MATRIX2;
	VECTOR2;
	
	MatrixXd x_colPivHouseholderQr;
	x_colPivHouseholderQr = (A1.colPivHouseholderQr().solve(B1));
	std::cout << "The solution X is:\n"
		<< x_colPivHouseholderQr << std::endl;
	
	MatrixXd y_colPivHouseholderQr;
	y_colPivHouseholderQr = (A2.colPivHouseholderQr().solve(B2));
	std::cout << "The solution Y is:\n"
		<< y_colPivHouseholderQr << std::endl;


	Mat input;
	Mat output;
	MatrixXd map(2,3);
	map <<
		0.867, 0.062, -10,
		-0.325, 1.037, 147.562;
	Mat map2;
	eigen2cv(map, map2);
	
	//cout << map2;

	input=imread("A.png");
	cv::Size src_sz = input.size();
	cv::Size dst_sz(src_sz.height, src_sz.width);
	//cout << dst_sz << endl;
	warpAffine(input, output, map2, dst_sz);
	imshow("haha", output);
	waitKey();
	system("pause");


	

}
