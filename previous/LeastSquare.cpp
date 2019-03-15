// LeastSquare.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "class.h"
#include <fstream>
#include <sstream>

MyPoint processLine(string temp)/*将字符串通过流导入点（X,Y,Z）*/
{
	stringstream str;
	double X = 0.0, Y = 0.0, Z = 0.0;
	short illu;
	str << temp;
	str >> X;
	str >> Y;
	str >> Z;
	str >> illu;
	MyPoint tempPt(X, Y, Z, illu);
	return tempPt;
}
int main()
{
	vector<MyPoint> cloud;

	string filename = "read.asc";
	ifstream ReadFile;
	string temp;
	ReadFile.open(filename);
	if (ReadFile.fail()) { printf("文件不存在"); return 0; }
	if (!getline(ReadFile, temp)) { printf("文件为空");  return 0; }
	while (getline(ReadFile, temp))
	{
		MyPoint tempPt = processLine(temp);
		cloud.push_back(tempPt);
	}

	LeastSquare LS(cloud);
	vector<MyPoint> Outcloud;
	LS.print();
	LS.filter(cloud, Outcloud);

    return 0;
}

