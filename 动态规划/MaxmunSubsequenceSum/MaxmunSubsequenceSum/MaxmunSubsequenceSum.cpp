// MaxmunSubsequenceSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"
#include <iostream>
#include "windows.h"
//动态规划方法
int DynamicProgram(int n, int *a)
{
	int sum = 0, b = 0;
	for (int i = 0;i < n ;i++)
	{
		if (b > 0) b += a[i];
		else
			b = a[i];
		if (b > sum) sum = b;
	}
	std::cout << "in Dynamic: " << b << std::endl;
	return sum;
}

int main()
{
	
	int a[] = { 6, 11, -4, 13, -5, -2 };
	int MaxSumB = -1;//BruteForce
	int i, j = 0;

	DWORD start_time = GetTickCount();
	MaxSumB = BruteForce(3, a, i, j);
	DWORD B_time = GetTickCount();

	int MaxSumF = -1;//sub rule
	MaxSumF = sub_rule(6, a);
	DWORD F_time = GetTickCount();
	int MaxSumD = -1;//dongtaigui
	MaxSumD = DynamicProgram(6, a);
	DWORD D_time = GetTickCount();
	std::cout << "BruteForce: " << MaxSumB << ",  i = "<< i <<", j = "<< j <<", time =  " << B_time - start_time << "ms" << std::endl;
	std::cout << "Sub_Rule: " << MaxSumF << ", time =  " << F_time - start_time << "ms" << std::endl;
	std::cout << "DynamicProgram: " << MaxSumD << ", time =  " << D_time - start_time << "ms" << std::endl;
    return 0;
}

