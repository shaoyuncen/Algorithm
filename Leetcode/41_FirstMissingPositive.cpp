#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
// int firstMissingPositive(vector<int> &nums) // O(n) time O(n) space
// {
//     if (nums.empty())
//         return 1;
//     unordered_map<int, int> map;
//     int min = -1;
//     for (size_t i = 0; i < nums.size(); i++)
//     {
//         if (nums[i] < 1)
//             continue;
//         if (min == -1)
//             min = nums[i];
//         if (nums[i] < min)
//             min = nums[i];
//         map[nums[i]] = i;
//     }
//     if (min == -1)
//         return 1;
//     int missing = min + 1;
//     if (min > 1)
//         return 1;
//     while (map.find(missing) != map.end())
//     {
//         missing++;
//     }
//     return missing;
// }
//下面的代码又臭又长，但是执行是对的，所以不想改了
int firstMissingPositive(vector<int> &nums) //O(n) time O(1) space
{
    int size = nums.size();
    for (int i = 0; i < size; ++i)
        while (nums[i] > 0 && nums[i] <= size && nums[nums[i] - 1] != nums[i])
            swap(nums[i], nums[nums[i] - 1]);

    for (int i = 0; i < size; i++)
    {
        if (nums[i] != (i + 1))
            return i + 1;
    }
    return size + 1;
}
int main()
{
    vector<int> nums = {-1, 4, 2, 1, 9, 10};
    cout << firstMissingPositive(nums);
    return 0;
}