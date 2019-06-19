#include <iostream>
#include <queue>
#include <vector>
#include<functional>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;//min heap

        for(int i=0;i<(int)nums.size();++i)
        {
            if(heap.size()<k)
                heap.push(nums[i]);
            else
            {
                if(nums[i] >= heap.top())
                {
                    heap.pop();
                    heap.push(nums[i]); 
                }
            }
        }
        return heap.top();
    }
int main(int argc, char const *argv[])
{
    vector<int> nums({1,3,4,2,5});
    int result = findKthLargest(nums, 3);
    cout<<result<<endl;


    return 0;
}
