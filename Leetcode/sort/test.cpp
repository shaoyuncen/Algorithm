#include <iostream>
#include <vector>
using namespace std;

int findNumsMin(vector<int> & nums){
    int minNum = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] < minNum)
            minNum = nums[i];
    }
    return minNum;
}

int countSlid(vector<int> & nums, int n, int k){
    int t = findNumsMin(nums);
    if(t > k)
        return n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if(nums[i] == t) count++;
    }
    return n - count;
}

int main(){
    int n ,k;
    cin>>n>>k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }
    vector<int >data(arr,arr + sizeof(arr)/ sizeof(int));
    int res = countSlid(data,data.size(),3);
    cout<<res;
}