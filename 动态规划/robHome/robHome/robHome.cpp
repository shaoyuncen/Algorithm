// robHome.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define max(a, b) {(a)>(b)?(a):(b)}

//打劫问题，必须隔一家打劫，最后求最优打劫序列
int rob(int n, int *a)
{
	if (n == 0) return 0;
	if (n == 1) return a[0];
	long DP_i_1 = a[1];
	long DP_i_2 = a[0];
	for (int i = 2;i < n; i++)
	{
		long temp = DP_i_1;//temp保存Vi-2
		DP_i_1 = max(DP_i_1, DP_i_2 + a[i]); //比较Vi-2 + a[i] 和Vi-1来更新Vi,因为i++后这里的Vi变成Vi-1
		DP_i_2 = temp;
	}
	return DP_i_1;
}

int main()
{
	int a[] = { 3, 8, 4, 2, 6, 5, 10, 3 };
	int a_index[10] = { 0 };
	std::cout << "最大打劫和为： " << rob(8, a) << std::endl;
	for (int i = 0; a_index[i] != 0 && i < 10;i++)
	{
		std::cout << a_index[i] << " ";
	}
	return 0;
}