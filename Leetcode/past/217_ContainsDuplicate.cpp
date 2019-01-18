#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
bool containsDuplicate(vector<int> &nums)
{
    return set<int>(nums.begin(), nums.end()).size() < nums.size();
}
int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    if(containsDuplicate(nums))
        cout << "Yes, There is a number appearing twice." << endl;
    else
    {
        cout << "No, None number appears twice." << endl;
    }
    return 0;
}