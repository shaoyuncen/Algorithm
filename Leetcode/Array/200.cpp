#include "head.h"

using namespace std;

vector<int> vec;
int row;
int col;
int Find(int x)//根节点的值和下标相同
{
    if(x != vec[x])//如果不是根节点
        return Find(vec[x]);
    return vec[x];//return 根节点的下标
}

int calIdx(int i, int j) { return i * col + j + 1; }
int numIslands(vector<vector<char>>& grid) {
    row = grid.size();//行
    col = grid[0].size();
    int counts = row * col;
    vec.resize(row * col + 1);
 
    for (int i = 1; i <= counts;i++)
        vec[i] = i;
        
    for (int i = 0; i < row;i++)
    {
        for (int j = 0; j < col; j++)
        {
            int idx = calIdx(i,j);//i,j 对应vec的下标 (i+1-1)*col+j+1   i * col + j + 1
            if (grid[i][j] == '1')
            {
                if(i==0&&j==0)
                    continue;
                else
                {
                    if(i>0&&grid[i-1][j] == '1')//上面的等于1
                    {
                        vec[Find(idx)] = Find(calIdx(i - 1, j));//把上面的根的值 赋给 当前的节点
                    }
                    if(j>0&&grid[i][j-1] == '1')//前面等于1
                    {
                        vec[Find(idx)] = Find(calIdx(i, j - 1));//把上面的根的值 赋给 当前的节点
                    }
                    
                }
            }
            else//'0'
                vec[idx] = 0;
        }
    }

    int count=0;
    for (int i = 1; i <= counts; i++)
    {
        if(vec[i]==0)
            continue;
        if(vec[i]==i)
            count++;
    }
    for(auto num : vec)
        cout << num << ' ';
    cout << endl;

    return count;
}
int main()
{
    vector<vector<char>> grid({{'1', '1', '0', '0', '0'}, 
                                {'1', '1', '0', '0', '0'}, 
                                {'0', '0', '1', '0', '0'}, 
                                {'0', '0', '0', '1', '1'}});
    int result;
    result = numIslands(grid);
    cout << "output: "<<result << endl;

    return 0;
}