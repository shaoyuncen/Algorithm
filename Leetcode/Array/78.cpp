#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int>& nums, int pos, vector<int>& path, vector<vector<int>>& result)
{
    if(pos == nums.size())    return;
    for(int i = pos; i < nums.size(); i ++)
    {
        path.push_back(nums[i]);
        result.push_back(path);
        dfs(nums, i + 1  , path, result);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> path;
    result.push_back(path);
    if(nums.empty())    return result;
    dfs(nums, 0, path, result);
    return result;
}

int main()
{
    vector<int> nums({1, 2});
    vector<vector<int>> results(subsets(nums)); // ({{1},{2},{1,2,3},{1,2},{}});
    for (int i = 0; i < static_cast<int>(results.size()); i++)
    {
        for (int j = 0; j < (int)results[i].size(); j++)
            cout << results[i][j] << ' ';
        cout << endl;
    }
    
    return 0;
}



// void insert(vector<vector<int>> &results, const vector<int> &nums)
// {
//     int size = nums.size();
//     if(size == 2) return ;
//     for(int i = 0; i < size; i++)
//     {
//         vector<int> result;
//         for(int j = 0;j<size;j++)
//         {
//             if(j!=i)
//                 result.push_back(nums[j]);
//         }
//         results.push_back(result);
//         insert(results, result);
//         result.pop_back();
//     }
// }
// vector<vector<int>> subsets(vector<int>& nums) 
// {
//     vector<vector<int>> results;
//     vector<int> none(0);
//     results.push_back(none);
//     insert(results, nums);
//     return results;
// }