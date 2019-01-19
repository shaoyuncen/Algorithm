#include <iostream>
#include <vector>
using namespace std;
void print(vector<int> vec)
{
    for(auto num : vec)
    {
        cout << num << ' ';
    }
    cout << endl;
}
vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int fromBegin=1;
        int fromLast=1;
        vector<int> res(n,1);
        
        for(int i=0;i<n;i++){
            res[i]*=fromBegin;
            fromBegin*=nums[i];
            res[n-1-i]*=fromLast;
            fromLast*=nums[n-1-i];
            cout << "i: "<< i << " fromBegin: " << fromBegin << " fromLast: " << fromLast<<endl;
            print(res);
        }
        return res;
    }
int main(int argc, char const *argv[])
{

    vector<int> nums = {1, 2, 3, 4};
    vector<int> result = productExceptSelf(nums);
    
    return 0;
}
