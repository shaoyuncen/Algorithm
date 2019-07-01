#include <vector>
using std::vector;
bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size<=1)
            return true;
        int farthest = nums[0];
        for(int i = 0; i <= farthest && i < size-1;i++)
        {
            farthest = (nums[i]+i) > farthest? (nums[i]+i) : farthest;
            if(farthest>=size-1)
                return true;
        }
        if(farthest>=size-1)
            return true;
        else
            return false;
    }