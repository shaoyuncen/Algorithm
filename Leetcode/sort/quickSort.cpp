#include <iostream>

using namespace std;


int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            --high;
 
        A[low] = A[high]; //将比枢轴值小的元素移到左边
 
        while (low < high && A[low] <= pivot)
            ++low;
 
        A[high] = A[low]; //将比枢轴值小的元素移到右边
        }
        A[low] = pivot;  //将枢轴值元素置于最终位置
        return low;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high) //递归跳出条件
    {
        //Partition就是上面的划分操作
        int pivot = Partition(A,low,high); //划分
 
        QuickSort(A,low,pivot-1); //左半部分递归
 
        QuickSort(A, pivot + 1, high); //右半部分递归
    }
}
