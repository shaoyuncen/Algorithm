//有序容器的搜索，二分都是最佳办法
#include <iostream>
#include <vector>
using namespace std;
int BinarySearch(vector<int> nums, int val, int left, int right)
{
    if(left > right)
        return -1;
    int mid = (left + right) / 2;
    if(nums[mid] == val)
        return mid;
    else if(nums[mid] < val)
        return BinarySearch(nums, val, mid+1, right);
    else
        return BinarySearch(nums, val, left, mid-1);
}
int BinarySearchIter(vector<int> nums, int val)
{
    int left = 0;
    int right = nums.size();
    while(left>=right)
    {
        int mid = (left + right) / 2;
        if(val == nums[mid])
            return mid;
        else if(nums[mid] < val)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}