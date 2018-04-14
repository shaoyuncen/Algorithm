#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//夹逼的方法，先排序，然后在最左和最右中间搜索
vector<vector<int>> threeSum(vector<int> &nums)
{
	vector<vector<int>> solution;
	if(nums.size()<3)
		return solution;
	sort(nums.begin(), nums.end());
	int i = 0, last = nums.size() - 1;
	while(i < last)
	{
		int a = nums[i], j = i + 1, k = last;
		while(j < k)
		{
			int b = nums[j], c = nums[k], sum = a + b + c;
			if(sum == 0)
				solution.push_back({a, b, c});
			if(sum<=0)
				while(nums[j] == b && j < k)	j++;
			if(sum>=0)
				while(nums[k] == c && j < k )	k--;
		}
		while(nums[i] == a && i < last)
			i++;
	}
	return solution;
}
//下面的方法利用了2Sum的方法，但是无法去掉重复的
// vector<vector<int>> threeSum2(vector<int> &nums)
// {
// 	vector<vector<int>> solution;
// 	if (nums.size()<3)    return solution;
// 	sort(nums.begin(), nums.end());
// 	for (size_t i = 0; i < nums.size() - 2; i++)
// 	{
// 		if (i>0 && nums[i] == nums[i - 1]) continue;
// 		int target = 0 - nums[i];
// 		unordered_map<int, int> map; //number and index
// 		for (size_t j = i + 1; j < nums.size(); j++)
// 		{
// 			if (map.find(target - nums[j]) != map.end())
// 			{
// 				vector<int> temp(3);
// 				temp[0] = nums[i]; //当前数
// 				temp[1] = target - nums[j]; //当前数后面的2Sum对
// 				temp[2] = nums[j];//当前数后面的2Sum对
// 				solution.push_back(temp);
// 			}
// 			else
// 			{
// 				map[nums[j]] = j;
// 			}

// 		}
// 		map.clear();
// 	}
// 	return solution;
// }

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> solution(threeSum(nums));
    for (vector<vector<int>>::iterator it = solution.begin(); it != solution.end(); it++)
    {
        for (vector<int>::iterator iter = it->begin(); iter != it->end(); iter++)
        {
            cout << *iter << ' ';
        }
        cout << endl;
    }
    return 0;
}