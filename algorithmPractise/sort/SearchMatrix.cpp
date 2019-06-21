//有序矩阵中找某个数
#include <vector>
using std::vector;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m==0)
        return false;
    int n = matrix[0].size();
    if(n==0)
        return false;
    if(target<matrix[0][0] || target > matrix[m-1][n-1])
        return false;
    int lower = 0;
    int upper = m*n-1;
    while(lower <= upper)
    {
        int mid= (lower+upper)/2;
        int x_ = mid/n;
        int y_ = mid%n;
        if(target==matrix[x_][y_])
            return true;
        else if(target<matrix[x_][y_])
            upper = mid - 1;
        else
            lower = mid + 1;
    }
    return false;
}
