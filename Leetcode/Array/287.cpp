#include "../common.h"

using namespace std;

int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int restart = 0;
        while(restart != slow)
        {
            restart = nums[restart];
            slow = nums[slow];
        }
        return slow;
    }
int main()
{
    vector<int> nums({1,3,4,2,2});
    int res = findDuplicate(nums);
    cout << res << endl;
    return 0;
}