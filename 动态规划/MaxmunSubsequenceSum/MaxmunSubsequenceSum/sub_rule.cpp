
#include "stdafx.h"
#include "head.h"
//分治法
int MaxSum(int *a, int left, int right) 
{
	int sum = 0;
	if (left == right) sum = a[left] > 0 ? a[left] : 0;  //左右相等则跟0比，程序出口
	else 
	{
		int center = (left + right) / 2;
		int leftsum = MaxSum(a, left, center);
		int rightsum = MaxSum(a, center + 1, right);
		int s1 = 0;
		int lefts = 0;
		for (int i = center;i >= left;i--)
		{
			lefts += a[i];
			if (lefts > s1) s1 = lefts;
		}
		int s2 = 0;
		int rights = 0;
		for (int i = center + 1;i <= right; i++)
		{
			rights += a[i];
			if (rights > s2) s2 = rights;
		}
		sum = s1 + s2;
		if (sum < leftsum) sum = leftsum;
		if (sum < rightsum) sum = rightsum;
	}
	return sum;
}
int sub_rule(int n, int *a)
{ 
	return MaxSum(a, 0, n-1);
}

//T(n) = O(nLog n)