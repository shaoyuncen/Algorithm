#include "tree.h"
#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
//先中序遍历存在vector中，然后通过index判断
int main(int argc, char const *argv[])
{
    vector<vector<int>> nums = {{3},{9,20},{15,7}};
    
    // vector<vector<int>> result;
    // for(int i=(int)nums.size()-1;i>=0;i--)
    // {
    //     vector<int> tmp(nums[i]);
    //     result.push_back(tmp);
    // }
    reverse(nums.begin(), nums.end());
    for(int i=0;i<(int)nums.size();++i)
        for(int j=0;j<(int)nums[i].size();++j)
            std::cout<<nums[i][j]<<std::endl;
    
        
    return 0;
}
