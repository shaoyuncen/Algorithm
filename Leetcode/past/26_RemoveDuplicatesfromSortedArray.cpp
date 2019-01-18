#include <iostream>
#include <set>
#include <vector>
using namespace std;
int removeDuplicates2(vector<int> &nums)
{
    set<int> sets(nums.begin(), nums.end());
    nums.clear();
    for (set<int>::iterator it = sets.begin(); it != sets.end(); it++)
    {
        nums.push_back(*it);
    }
    return nums.size();
}
int removeDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    int count = 0;
    for (int i = 1; i < (int)nums.size(); i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        else
        {
            count++;
            nums[count] = nums[i];
        }
    }
    int counts = (int)nums.size() - count - 1;

    while (counts)
    {
        nums.pop_back();
        counts--;
    }
    return nums.size();
}
int main()
{
    return 0;
}