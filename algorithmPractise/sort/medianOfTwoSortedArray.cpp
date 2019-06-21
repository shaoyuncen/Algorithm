#include <iostream>
#include <vector>
#define min(a,b) a<b?a:b
using namespace std;
double findMedianSortedArrHelper(vector<int> &nums1, vector<int>&nums2, int left1, int right1, int left2, int right2, int k)
{//两个有序数组找k大，对K进行二分，搜索，每一次都要舍弃k/2的数，并且更新k
    if(right1 == -1 || left1>right1)//A的left>right或者A为空
        return nums2[left2+k-1];
    if(right2 == -1 || left2>right2)//B的left>right或者B为空
        return nums1[left1+k-1];

    if(k==1)//找A,B中最小
        return min(nums1[left1], nums2[left2]);

    int mid1 = left1 + k/2 - 1;
    int mid2 = left2 + k/2 - 1;
    if(mid1>right1)
    {//A的长度不够k/2, 丢B的k/2，因为B的前k/2一定都比median小,不管A的数全比中位数小或者大，B的前k/2都比中位数小
        return findMedianSortedArrHelper(nums1, nums2, left1, right1, left2+k/2, right2, k-k/2);
    }
    if(mid2>right2)
    {//B的长度不够k/2，丢A的k/2，原因同上
        return findMedianSortedArrHelper(nums1, nums2, left1+k/2, right1, left2, right2, k-k/2);
    }
    if(nums1[mid1] <= nums2[mid2])
    {//丢A，A[k/2-1]<=B[k/2-1] => A[0]-A[k/2-1]都比median小
        return findMedianSortedArrHelper(nums1, nums2, left1+k/2, right1, left2, right2, k-k/2);
    }
    else
    {//丢B
        return findMedianSortedArrHelper(nums1, nums2, left1, right1, left2+k/2, right2, k-k/2);
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int left1 = 0, right1 = (int)nums1.size()>0? nums1.size() - 1 : -1;
    int left2 = 0, right2 = (int)nums2.size()>0? nums2.size() - 1 : -1;
    int size = nums1.size() + nums2.size();
    int k1, k2;
    if(size%2==0)
    {
        k1 = size/2;
        k2 = k1+1;
    }
    else
    {
        k1=size/2+1;
        k2 = k1;
    }
    // cout<<k1<<' '<<k2<<endl;
    double m1 = findMedianSortedArrHelper(nums1, nums2, left1, right1, left2, right2, k1);
    double m2 = findMedianSortedArrHelper(nums1, nums2, left1, right1, left2, right2, k2);
    return (m1+m2)/2.0;

}
int main(int argc, char const *argv[])
{
    vector<int> nums1({1});
    vector<int> nums2({});
    double result = findMedianSortedArrays(nums1, nums2);
    cout<<"result: "<<result<<endl;

    return 0;
}
