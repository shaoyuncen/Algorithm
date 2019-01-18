#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size();
    bool signal = false;
    digits[size - 1] += 1;
    for (int i = size - 1; i >= 0; i--)
    {
        digits[i] += (signal ? 1 : 0);
        signal = false;
        if(digits[i] > 9) 
        {
            signal = true;
            digits[i] %= 10;
        }
        else
            break;
    }
    if(signal)
        digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    vector<int> nums = { 1, 2, 9};
    plusOne(nums);
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << endl;
    }
    return 0;
}