#include<iostream>
#include<cstdlib>
#include<Eigen/Dense>
#include<Eigen/SVD>
#include<opencv2/core/core.hpp>
#include<opencv.hpp>
//#include<opencv2/core/eigen.hpp>
#include<fstream>

#define MATRIX1 A1 <<\
0.34853, 1.40218, 3.16080,\
0.38464, 1.15958, 2.85423,\
0.35751, 0.96060, 3.08704,\
0.54920, 0.98926, 3.14159,\
0.57325, 1.33776, 3.14033,\
0.59516, 1.68564, 3.19424,\
0.45038, 0.87225, 3.13210,\
0.50442, 0.49793, 3.07118,\
0.55065, 0.35895, 2.96469,\
0.55300, 0.22239, 2.84522,\
0.40856, 0.60252, 2.68509,\
0.23837, 0.61958, 2.83885,\
0.37659, 0.45965, 2.99499,\
0.64058, 0.45710, 3.10955,\
0.74329, 0.64328, 3.22588,\
0.76410, 0.75327, 3.05714;

#define MATRIX2 	B1 <<\
0.34125, 1.74468, 3.10297,\
0.34534, 1.38732, 2.94041,\
0.32255, 1.10448, 3.05881,\
0.51266, 1.11136, 3.12476,\
0.56068, 1.45724, 3.11503,\
0.53296, 1.78601, 3.23972,\
0.40724, 1.00421, 3.09389,\
0.44052, 0.63998, 2.97995,\
0.48319, 0.51520, 2.85586,\
0.48294, 0.39777, 2.71751,\
0.37551, 0.93754, 2.56104,\
0.28020, 0.83528, 2.74368,\
0.31454, 0.62231, 2.89377,\
0.57171, 0.58454, 3.01729,\
0.64908, 0.78515, 3.12918,\
0.63194, 0.86380, 2.94338;



using namespace std;
using namespace cv;
using namespace Eigen;



int main()
{
	VectorXd U(16);
	VectorXd V(16);
	ofstream OUT_u_Xw("u_Xw.txt", ios::out | ios::app | ios::ate);
	ofstream OUT_u_Yw("u_Yw.txt", ios::out | ios::app | ios::ate);
	ofstream OUT_u_Zw("u_Zw.txt", ios::out | ios::app | ios::ate);
	ofstream OUT_v_Xw("v_Xw.txt", ios::out | ios::app | ios::ate);
	ofstream OUT_v_Yw("v_Yw.txt", ios::out | ios::app | ios::ate);
	ofstream OUT_v_Zw("v_Zw.txt", ios::out | ios::app | ios::ate);
	ofstream MATRIX_OUT("matrix.txt", ios::out | ios::app | ios::ate);
	ofstream V_OUT("v_out.txt", ios::out | ios::app | ios::ate);
	U <<
		273,
		253,
		263,
		343,
		353,
		363,
		303,
		323,
		323,
		323,
		233,
		183,
		263,
		373,
		423,
		413;
	V <<
		639,
		549,
		449,
		459,
		589,
		719,
		459,
		279,
		279,
		199,
		319,
		339,
		279,
		289,
		379,
		409;
	VectorXd Xw(16);
	VectorXd Yw(16);
	VectorXd Zw(16);
	
	Xw <<
		0.34853,
		0.38464,
		0.35751,
		0.54920,
		0.57325,
		0.59516,
		0.45038,
		0.50442,
		0.55065,
		0.55300,
		0.40856,
		0.23837,
		0.37659,
		0.64058,
		0.74329,
		0.76410;

	Yw <<
		1.40218,
		1.15958,
		0.96060,
		0.98926,
		1.33776,
		1.68564,
		0.87225,
		0.49793,
		0.35895,
		0.22239,
		0.60252,
		0.61958,
		0.45965,
		0.45710,
		0.64328,
		0.75327;

	Zw<<
		3.16080,
		2.85423,
		3.08704,
		3.14159,
		3.14033,
		3.19424,
		3.13210,
		3.07118,
		2.96469,
		2.84522,
		2.68509,
		2.83885,
		2.99499,
		3.10955,
		3.22588,
		3.05714;
		
	VectorXd u_Xw(16);
	VectorXd u_Yw(16);
	VectorXd u_Zw(16);
	
	for (int i = 0; i < 16; i++)
	{
		u_Xw(i) = U(i) * Xw(i);
	}
	if (OUT_u_Xw.is_open()) {
		OUT_u_Xw << u_Xw << endl;;
		//cout << u_Xw(0) << endl;
	}
	for (int i = 0; i < 16; i++)
	{
		u_Yw(i) = U(i) * Yw(i);
	}
	
	if (OUT_u_Yw.is_open())
	{
		OUT_u_Yw << u_Yw << endl;
	}

	for (int i = 0; i < 16; i++)
	{
		u_Zw(i) = U(i) * Zw(i);
	}

	if (OUT_u_Zw.is_open())
	{
		OUT_u_Zw << u_Zw << endl;
	}
	VectorXd v_Xw(16);
	VectorXd v_Yw(16);
	VectorXd v_Zw(16);

	for (int i = 0; i < 16; i++)
	{
		v_Xw(i) = V(i) * Xw(i);
	}
	
	if (OUT_v_Xw.is_open())
	{
		OUT_v_Xw << v_Xw << endl;
	}

	for (int i = 0; i < 16; i++)
	{
		v_Yw(i) = V(i) * Yw(i);
	}

	//if (OUT_v_Xw.is_open())
	//{
	//	OUT_v_Yw << v_Yw << endl;
	//}

	for (int i = 0; i < 16; i++)
	{
		v_Zw(i) = V(i) * Zw(i);
	}

	//if (OUT_v_Xw.is_open())
	//{
	//	OUT_v_Zw << v_Zw << endl;
	//}
	
	MatrixXd M_a(12, 12);
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (i % 2 == 0 && j == 0)
			{
				M_a(i, j) = Xw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 1)
			{
				M_a(i, j) = Yw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 2)
			{
				M_a(i, j) = Zw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 3)
			{
				M_a(i, j) = 1;
			}
			if (i % 2 == 0 && j == 4||j==5||j==6||j==7)
			{
				M_a(i, j) = 0;
			}
			if (i % 2 == 0 && j == 8)
			{
				M_a(i, j) = -u_Xw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 9)
			{
				M_a(i, j) = -u_Yw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 10)
			{
				M_a(i, j) = -u_Zw(i / 2 + 1);
			}
			if (i % 2 == 0 && j == 11)
			{
				M_a(i, j) = -U(i / 2 + 1);
			}

			if (i % 2 != 0)
			{
				if (j == 0 || j == 1 || j == 2 || j == 3)
				{
					M_a(i, j) = 0;
				}
				if (j == 4)
				{
					M_a(i, j) = Xw((i + 1) / 2);
				}
				if (j == 5)
				{
					M_a(i, j) = Yw((i + 1) / 2);
				}
				if (j == 6)
				{
					M_a(i, j) = Zw((i + 1) / 2);
				}
				if (j == 7)
				{
					M_a(i, j) = 1;
				}
				if (j == 8)
				{
					M_a(i, j) = -v_Xw((i + 1) / 2);
				}
				if (j == 9)
				{
					M_a(i, j) = -v_Yw((i + 1) / 2);
				}
				if (j == 10)
				{
					M_a(i, j) = -v_Zw((i + 1) / 2);
				}
				if (j == 11)
				{
					M_a(i, j) = -V((i + 1) / 2);
				}
			}

		}
	}
	cout << M_a << endl;
	MATRIX_OUT << M_a << endl;

	VectorXd B(18);
	for (int i = 0; i < 18; i++)
	{
		B(i) = 0;
	}

	VectorXd X(12);
	JacobiSVD<MatrixXd> svd(M_a, ComputeThinU | ComputeThinV);
	MatrixXd V1 = svd.matrixV(), U1 = svd.matrixU();
	MatrixXd  S1 = U1.inverse() * M_a * V1.transpose().inverse();
	cout << V1 << endl;
	V_OUT << "**************************************************" << endl;
	V_OUT << "the last row is the answer" << endl;
	V_OUT << V1 << endl;
	MatrixXd R_T(3, 4);
	MatrixXd M(3, 4);
	MatrixXd K(3,3);
	K <<
		746.07, 0, 493.9,
		0, 743.9, 488.7,
		0, 0, 1;



	M <<
		-0.05, 0.01, -0.12, 0.388,
		-0.05, 0.009, -0.276, 0.867,
		-.00015, -0.0024, -0.00004, 0.0014;

	R_T = K.inverse() * M;

	cout << "******************************" << endl;
	cout << "*******************************" << endl;
	cout << R_T << endl;

	system("pause");


}
