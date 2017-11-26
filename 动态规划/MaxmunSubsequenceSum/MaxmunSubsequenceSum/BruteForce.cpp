#include "head.h"
#include "stdafx.h"

int BruteForce(int n, int *a, int &besti, int &bestj)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int thissum = 0;
		for (int j = i; j <= n; j++)
		{
			thissum += a[j];
			if (thissum > sum)
			{
				sum = thissum;
				besti = i;
				bestj = j;
			}
		}
	}
	return sum;
}

//T(n) = O(n²); 