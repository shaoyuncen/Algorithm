#include "../common.h"

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D)
{
    int res = 0;
    int size = A.size();
    unordered_map<int, int> ump; //sum, count
    for(int i=0; i< size;i++)//A+B
    {
        for(int j=0;j<size;j++)
        {
            int sum = A[i]+B[j];
            ump[sum]++;
        }
    }
    for(int i=0; i< size;i++)//A+B
    {
        for(int j=0;j<size;j++)
        {
            int sum = C[i]+D[j];
            if(ump.find(-sum)!=ump.end())
                res+=ump[-sum];
        }
    }
    
    return res;
}
int main()
{
    vector<int> A({1,2});
    vector<int> B({-2,-1});
    vector<int> C({-1,2});
    vector<int> D({0,2});
    int result = fourSumCount(A,B,C,D);
    cout<<"result: "<<result<<endl;
    return 0;
}