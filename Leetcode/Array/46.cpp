#include <iostream>
#include <vector>
#include <deque>
using namespace std;


vector<vector<int>> result;
vector<int> single;
vector<int> index_vec;

void recursion(const vector<int> &nums, deque<int> index_son)
{
    if(index_son.size() < 1)
    {
        result.push_back(single);
    }
    else
    {
        for(auto pos = index_son.begin(); pos!=index_son.end(); pos++ )
        {
            single.push_back(nums[*pos]);
            
            deque<int> temp(index_son.begin(), index_son.end());
            
            int present_index = distance(index_son.begin(), pos);
            
            temp.erase(temp.begin() + present_index);

            recursion(nums, temp);

            single.pop_back();
        }
    }
    
}
    
vector<vector<int>> permute(vector<int>& nums) {
    int size = nums.size();
    deque<int> index;
    for(int i = 0; i<size;i++)
        index.push_back(i);

    recursion(nums, index);
    return result;
}


int main(int argc, char const *argv[])
{
    vector<int> vecs = {1, 2, 3};
    vector<vector<int>> result(permute(vecs));
    for(auto vec : result)
    {
        for(auto num : vec)
            cout << num <<" ";
        cout << endl;
    }

    return 0;
}
