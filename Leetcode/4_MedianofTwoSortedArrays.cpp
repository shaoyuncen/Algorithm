#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    double median;
    vector<int> newArray;
    int i = 0, j = 0, m = nums1.size(), n = nums2.size();

    while (i < m || j < n)
    {
        while (i < m && j < n && nums1[i] < nums2[j])
        {
            newArray.push_back(nums1[i]);
            i++;
        }

        while (i < m && j < n && nums1[i] > nums2[j])
        {
            newArray.push_back(nums2[j]);
            j++;
        }
        while (i < m && j < n && nums1[i] == nums2[j])
        {
            newArray.push_back(nums1[i]);
            i++;
            newArray.push_back(nums2[j]);
            j++;
        }
        if (i == m)
            while (j < n)
            {
                newArray.push_back(nums2[j]);
                j++;
            }
        else if (j == n)
            while (i < m)
            {

                newArray.push_back(nums1[i]);
                i++;
            }
        else
            continue;
    }
    int size = newArray.size();
    for (size_t i = 0; i < size; i++)
    {
        cout << newArray[i] << endl;
    }
    if (size % 2 == 0)
        median = double(newArray[size / 2 - 1] + newArray[size / 2 ]) / 2;
    else
        median = double(newArray[size / 2]);
    return median;
}
int main()
{
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
} 