// robHome.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#define max(a, b) {(a)>(b)?(a):(b)}

//������⣬�����һ�Ҵ�٣���������Ŵ������
int rob(int n, int *a)
{
	if (n == 0) return 0;
	if (n == 1) return a[0];
	long DP_i_1 = a[1];
	long DP_i_2 = a[0];
	for (int i = 2;i < n; i++)
	{
		long temp = DP_i_1;//temp����Vi-2
		DP_i_1 = max(DP_i_1, DP_i_2 + a[i]); //�Ƚ�Vi-2 + a[i] ��Vi-1������Vi,��Ϊi++�������Vi���Vi-1
		DP_i_2 = temp;
	}
	return DP_i_1;
}

int main()
{
	int a[] = { 3, 8, 4, 2, 6, 5, 10, 3 };
	int a_index[10] = { 0 };
	std::cout << "����ٺ�Ϊ�� " << rob(8, a) << std::endl;
	for (int i = 0; a_index[i] != 0 && i < 10;i++)
	{
		std::cout << a_index[i] << " ";
	}
	return 0;
}