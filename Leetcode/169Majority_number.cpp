#include <iostream>
#include <vector>
using namespace std;
int majorityElement(vector<int> &nums)
{
    int number = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            count = 1;
            number = nums[i];
        }
        else if (nums[i] == number)
            count++;
        else
            count--;
    }
    return number;
}
int main()
{
    vector<int> nums = {1,2,1,3,4,5,11,1,1,1,1,1,1};
    int number = 0;
    number = majorityElement(nums);
    cout << number << endl;
    return 0;
}