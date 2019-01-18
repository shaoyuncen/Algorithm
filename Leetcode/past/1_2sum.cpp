#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
vector<int> Two_sum(vector<int> &nums, int target)
{
    unordered_map<int, int> map; //前面是数，后面是下标
    vector<int> pair;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if(map.find(target-nums[i])!= map.end())
        {//如果找到这个目标数
            pair.push_back(target - nums[i]);
            pair.push_back(i);
            break;
        }
        else
        {
            map[nums[i]] = i;
        }
    }
    map.clear();
    return pair;
}
int main()
{
    cout << "hello world!" << endl;
    return 0;
}