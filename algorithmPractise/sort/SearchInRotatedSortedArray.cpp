#include <vector>
using std::vector;

int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]>=nums[left])
            {//左有序
                if(target<=nums[mid]&&target>=nums[left])//在左边
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {//右有序
                if(target>=nums[mid]&&target<=nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }