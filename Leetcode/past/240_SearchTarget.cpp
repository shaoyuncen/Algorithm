#include <iostream>
#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size();
    int n = m != 0 ? matrix[0].size() : 0;
    int i = 0, j = n - 1;
    if (m == 0 || n == 0)
        return false;

    while (i < m && j >= 0)
    {
        int x = matrix[i][j];
        if (target == x)
            return true;
        else if (target < x)
            --j;
        else
            ++i;
    }
    return false;
}
int main()
{
    return 0;
}