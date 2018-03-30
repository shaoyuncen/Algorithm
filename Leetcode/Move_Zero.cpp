// GIVEN AN ARRAY NUMS, WRITE A FUNCTION TO MOVE ALL 0'S TO THE END OF IT WHILE MAINTAINING THE RELATIVE ORDER OF THE NON - ZERO ELEMENTS.

// FOR EXAMPLE,
//GIVEN NUMS = [ 0, 1, 0, 3, 12 ], AFTER CALLING YOUR FUNCTION, NUMS SHOULD BE[1, 3, 12, 0, 0].

//   = NOTE : YOU MUST DO THIS IN -
//   =PLACE WITHOUT MAKING A COPY OF THE ARRAY.MINIMIZE THE TOTAL NUMBER OF OPERATIONS.
//Leetcode 283
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        int count = 0;
        int index = 0;
        int temp = nums.size();
        for (unsigned int i = 0; i < temp; i++)
        {
            if (nums[i] == 0)
                count++;
            else
            {
                nums[index] = nums[i];
                index++;
            }
        }
        for (int i = 0; i < count; i++)
        {
            nums[temp - 1] = 0;
            temp--;
        }
    }
};
int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution sol;
    
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    sol.moveZeroes(nums);
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    return 0;
}