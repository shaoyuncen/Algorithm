// QuickSort.cpp : 定义控制台应用程序的入口点。
//
//分治法实例：快速排序                                                                                                                                                                                                                                                                                                                                                                                                                           
#include "stdafx.h"
#include <iostream>

template < class Type >
void Swap(Type &a, Type &b)
{
	Type temp;
	temp = a;
	a = b;
	b = temp;
}//swap a and b
template < class Type >
Type Median3(Type a[], int left, int right)
{
	int center = (left + right) / 2;
	//make sure left is min, right is max of the three nums
	if (a[left] > a[center]) 
		Swap(a[left], a[center]);
	if (a[left] > a[right]) 
		Swap(a[left], a[right]);
	if (a[center] > a[right]) 
		Swap(a[center], a[right]);
	Swap(a[center], a[right - 1]);
	return a[right - 1];//as the q
}
template < class Type >
void InsertionSort(Type a[], int N)
{
	int j, P;
	Type tmp;
	for (P = 1;P < N;P++)
	{
		tmp = a[P];
		for (j = P;j > 0 && a[j - 1] > tmp;j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

template < class Type >
void QuickSort(Type a[], int left, int right)
{
	int i, j;
	Type q;
	if (left + 3 <= right)
	{
		i = left;
		j = right - 1;
		q = Median3(a, left, right);
		while (true)
		{
			while (a[++i] < q);//find the number that bigger than q from left to right
			while (a[--j] > q);//find the number that samller than q from right to left
			if (i < j)
				Swap(a[i], a[j]);
			else
				break;
		}
		Swap(a[i], a[right - 1]); //restore the q
		QuickSort(a, left, i - 1);
		QuickSort(a, i + 1, right);
	}
	else
		InsertionSort(a + left, right - left + 1);
}//递归过程



