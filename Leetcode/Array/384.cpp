#include "../common.h"
using namespace std;

class Solution {
public:
    Solution(vector<int>& nums):vec(nums) {
        
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        if(vec.size()==0) return {};
        vector<int> tem(vec);
        int len = vec.size();
        for(int i = 0; i < len; i++)
        {
            int pos = rand()%(len-i);
            swap(tem[i+pos], tem[i]);
        }//思路: 在随机产生一个序列的时候, 遍历每一个元素, 并且随机一个从他开始的位置与这个位置交换, 这样任意一个元素随机到任意一个位置的概率都是1/n!.
        return tem;

    }
private:
    vector<int> vec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
int main()
{
    vector<int> nums({1,2,3,NULL});
    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();
    cout<<"param_1: ";
    for(auto num:param_1)
        cout<<num<<' ';
    cout<<endl;
    cout<<"param_2: ";
    for(auto num:param_2)
        cout<<num<<' ';
    cout<<endl;  
}