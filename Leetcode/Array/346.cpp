#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap;//value, frequence
        int size = nums.size();
        for(int i = 0; i < size; i++)
        {
            if(umap.find(nums[i])!=umap.end())
                umap[nums[i]]++;
            else
                umap[nums[i]] = 1;
        }
        vector<int> result;
        while(k)
        {
            int max = umap.begin()->second;
            int value = umap.begin()->first;
            for (auto it = umap.begin(); it != umap.end(); it++)
            {
                if(it->second > max)
                {
                    max = it->second;
                    value = it->first;
                }
                else
                    continue;
            }
            result.push_back(value);
            umap.erase(value);
            k--;
        }
    
        return result;
}
int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 1;
    vector<int> result = topKFrequent(nums, k);
    for(auto num:result)
        cout << num << ' ';
    cout << endl;
    return 0;
}
