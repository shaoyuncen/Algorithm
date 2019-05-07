#include "../common.h"

using namespace std;
class Solution{
public:
    int divideArea(const vector<vector<char>> &matrix);
};
int Solution::divideArea(const vector<vector<char>> &mtx)
{
    const int N = matrix.size();
    if(N==0)
        return 0;
    const int M = matrix[0].size();
    
    


    int res = 0;
    return res;
}
int main()
{
    int N = 3, M = 4;
    vector<vector<char>> matrix({{'/', '\\', '/', '\\'},
                                 {'\\', ' ', ' ', '/'},
                                 {' ', '\\', '/', '\\'}});
    Solution sol;
    int res = sol.divideArea(matrix);
    cout << "result: " << res << endl;
    return 0;
}