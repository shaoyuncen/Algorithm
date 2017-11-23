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

template <class Type>
void EasyQuickSort(Type a[], int left, int right)
{
	if (left < right)
	{
		int i = left, j = right + 1;
		Type q = a[left];
		while (true)
		{
			while (a[++i] < q);
			while (a[--j] > q);
			if (i < j)
				Swap(a[i], a[j]);
			else
				break;
		}
		a[left] = a[j];
		a[j] = q;
		EasyQuickSort(a, left, j - 1);
		EasyQuickSort(a, j + 1, right);
	}
}
int main()
{
	int a[] = { 2, 8, 7, 1, 3, 5, 6, 4 };
	EasyQuickSort(a, 0, 7);
	for (int i = 0;i < 8;i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
