#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int partition(int array[], int left, int right)
{
    int priot = array[right];
    int start = left;
    for(int i=left;i<right;++i)
        if(array[i]<=priot)
            swap(array[i],array[start++]);
    swap(array[right], array[start]);
    return start;
}
void qSort(int array[], int left, int right)
{
    if(left >= right)
        return;
    int index = partition(array, left, right);//轴值
    qSort(array, left, index-1);
    qSort(array, index+1, right);
}

void quick_sort(int array[], int size)
{
    qSort(array, 0, size-1);
}
int quick_select(int array[], int left, int right, int k)//k大元素
{
    if(left >= right)
        return array[left];
    int index = partition(array, left, right);//轴值
    int size = index-left+1;//偏移量
    if(size==k)
        return array[left+k-1];
    else if(size>k)
        quick_select(array, left, index-1, k);
    else
        quick_select(array, index+1, right, k-size);
}
int main(int argc, char const *argv[])
{
    int nums[] = {1,3,2,4,5};
    quick_sort(nums, 5);
    for(int i=0;i<5;++i)
        cout<<nums[i]<<' ';
    return 0;
}
