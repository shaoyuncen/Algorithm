#pragma once
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct MyPoint
{
	double x;
	double y;
	double z;
	short intensity;
	MyPoint() {  }
	MyPoint(double tx, double ty, double tz, short illu) {
		x = tx;
		y = ty;
		z = tz;
		intensity = illu;
	}
	bool operator==(const MyPoint& rhs) {
		return(x == rhs.x) && (y == rhs.y) && (z == rhs.z);
	}
	MyPoint operator+(const MyPoint& rhs) {
		MyPoint out;
		out.x = x + rhs.x;
		out.y = y + rhs.y;
		out.z = z + rhs.z;
		return out;
	}
	MyPoint operator/(const int n) {
		MyPoint out;
		out.x = x / n;
		out.y = y / n;
		out.z = z / n;
		return out;
	}
	MyPoint operator=(const MyPoint& rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		intensity = rhs.intensity;
		return MyPoint(x, y, z, intensity);
	}
	void MyPoint::print()
	{
		std::cout << "x = " << x << "  y = " << y << "  z = " << z << std::endl;
	}
};

class LeastSquare {
private:
	double k, b;
	double Variance;
	double StandardDeviation;
public:
	LeastSquare(const vector<MyPoint> &ptr) {
		k = 0.0; b = 0.0;
		compute(ptr);
		computeSum(ptr);
	}
	double getk() { return k; }
	double getb() { return b; }
	double getVariance() { return Variance; }
	double getStandardDeviation() { return StandardDeviation; }
	void compute(const vector<MyPoint> &ptr);//compute the k and b;
	void computeSum(const vector<MyPoint> &ptr);
	void filter(const vector<MyPoint> &ptr, vector<MyPoint> &outlier);
	void print()
	{
		cout << "y = " << k << "x + " << b << endl;
		cout << "方差为：" << Variance << ", 标准差为：" << StandardDeviation << endl;
	}
};
void LeastSquare::compute(const vector<MyPoint> &ptr) //compute k and b
{
	cout << "compute" << endl;
	double SumXi = 0.0;
	double SumYi = 0.0;
	double SumXi_2 = 0.0;
	double SumXiYi = 0.0;
	double deviation = 0.0;
	int number = ptr.size();
	for (int i = 0; i < number;i++)
	{
		SumXi += ptr[i].x;
		SumYi += ptr[i].z;
		SumXi_2 += ptr[i].x * ptr[i].x;
		SumXiYi += ptr[i].x * ptr[i].z;
	}

	double temp = (number * SumXi_2 - SumXi * SumXi);//减少计算次数
	k = (number * SumXiYi - SumXi * SumYi) / temp;
	b = (SumXi_2 * SumYi - SumXi * SumXiYi) / temp;
}
void LeastSquare::computeSum(const vector<MyPoint> &ptr) //compute variance
{
	double Var = 0.0;
	int number = ptr.size();
	for (int i = 0;i < number;i++)
	{
		double deviation = k * ptr[i].x + b - ptr[i].z;
		Var += deviation * deviation;
	}
	Variance = Var / number;
	StandardDeviation = sqrt(Variance);
}
void LeastSquare::filter(const vector<MyPoint> &ptr, vector<MyPoint> &outlier)
{
	for (int i = 0;i < ptr.size();i++)
	{
		double deviation = k * ptr[i].x + b - ptr[i].z;
		cout << deviation << " " << StandardDeviation << endl;
		if (deviation > StandardDeviation) {
			outlier.push_back(ptr[i]);
		}
	}

}



