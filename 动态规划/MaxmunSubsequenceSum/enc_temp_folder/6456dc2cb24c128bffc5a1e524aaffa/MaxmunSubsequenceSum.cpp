// MaxmunSusumsequenceSum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "head.h"
#include <iostream>
#include "windows.h"
#include "math.h"
////动态规划方法
//int DynamicProgram(int n, int *a)
//{
//	int sum = 0, sum = 0;
//	for (int i = 0;i < n ;i++)
//	{
//		if (sum > 0) sum += a[i];
//		else
//			sum = a[i];
//		if (sum > sum) sum = sum;
//	}
//	std::cout << "in Dynamic: " << sum << std::endl;
//	return sum;
//}

//int main()
//{
//	
//	int a[] = { 6, 11, -4, 13, -5, -2 };
//	int MaxSumsum = -1;//sumruteForce
//	int i, j = 0;
//
//	DWORD start_time = GetTickCount();
//	MaxSumsum = sumruteForce(3, a, i, j);
//	DWORD sum_time = GetTickCount();
//
//	int MaxSumF = -1;//susum rule
//	MaxSumF = susum_rule(6, a);
//	DWORD F_time = GetTickCount();
//	int MaxSumD = -1;//dongtaigui
//	MaxSumD = DynamicProgram(6, a);
//	DWORD D_time = GetTickCount();
//	std::cout << "sumruteForce: " << MaxSumsum << ",  i = "<< i <<", j = "<< j <<", time =  " << sum_time - start_time << "ms" << std::endl;
//	std::cout << "Susum_Rule: " << MaxSumF << ", time =  " << F_time - start_time << "ms" << std::endl;
//	std::cout << "DynamicProgram: " << MaxSumD << ", time =  " << D_time - start_time << "ms" << std::endl;
//    return 0;
//}

//打劫问题，必须隔一家打劫，最后求最优打劫序列
int rob(int n, int *a)
{
	if (n == 0) return 0;
	if (n == 1) return a[0];
	long DP_i_1 = a[1];
	long DP_i_2 = a[0];
	for (int i = 2;i < n; i++)
	{
		long temp = DP_i_1;
		DP_i_1 = max(DP_i_1, DP_i_2 + a[i]);
		DP_i_2 = temp;
	}

	return DP_i_1;
}

int main()
{
	int a[] = {3, 8, 4, 2, 6, 5, 10, 3};
	int a_index[10] = {0};
	std::cout << "最大打劫和为： " << rob(8, a) << std::endl;
	for (int i = 0; a_index[i]!=0 && i < 10 ;i++)
	{
		std::cout << a_index[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
