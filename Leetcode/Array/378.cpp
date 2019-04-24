#include "../common.h"
using namespace std;
int kthSmallest(vector<vector<int>>& matrix, int k) 
{
    priority_queue<int,vector<int>, less<int>> heap; //大跟堆
    for(int i=0; i<matrix.size(); ++i) {
        for(int j=0; j<matrix[0].size(); ++j) {
            if(heap.size() < k) heap.push(matrix[i][j]);//先存前k个数
            else {
                if(heap.top() <= matrix[i][j]) break;//然后继续遍历，如果比堆顶大，则略过
                else {
                    heap.push(matrix[i][j]);//比堆顶小，则加入堆，并删掉堆顶
                    heap.pop();
                }
            }
        }
    }
    return heap.top();
}

int main()
{
    vector<vector<int>> mat = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << kthSmallest(mat, 8) << endl;

    return 0;
}