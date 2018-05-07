#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void wiggleSort(vector<int> &nums)
{
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    //nth_element(start, start+n, end) 方法可以使第n大元素处于第n位置（从0开始,其位置是下标为 n的元素），
    //并且比这个元素小的元素都排在这个元素之前，比这个元素大的元素都排在这个元素之后，但不能保证他们是有序的
    int len = nums.size(), low = 0, high = len - 1, mid = nums[len / 2], i = 0;
    auto index = [=](int pos) { return (1 + pos * 2) % (len | 1); };
    while (i <= high)
    {
        if (nums[index(i)] > mid)
            swap(nums[index(i++)], nums[index(low++)]);
        else if (nums[index(i)] < mid)
            swap(nums[index(i)], nums[index(high--)]);
        else
            i++;
    }

}
int main()
{
 
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    wiggleSort(nums);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}