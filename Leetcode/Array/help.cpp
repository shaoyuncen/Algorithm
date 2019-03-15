#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;


int main() 
{
    unordered_map<int, int> nums;

    nums[1] = 1;
    nums[6] = 6;
    nums[2] = 2;
    nums[4] = 4;
    nums[5] = 5;
    nums[3] = 3;
    
    for(auto it = nums.begin(); it != nums.end(); ++it)
        cout << it->second;
    cout << endl;

    if(nums.find(1) != nums.end())
        cout << "hello" << endl;


    return 0;
}