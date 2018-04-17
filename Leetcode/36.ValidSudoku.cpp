#include <iostream>
#include <vector>
using namespace std;
bool notRepeat(vector<char> &group)
{
    int nums[9] = {0};
    for (int i = 0; i < 9; i++)
    {
        if (group[i] != '.')
            nums[group[i] - '0' - 1]++;
    }
    for (int i = 0; i < 9; i++)
    {
        if (nums[i] > 1)
            return false;
    }
    return true;
}
bool isValidSudoku(vector<vector<char>> &board)
{
    vector<char> row;
    for (int i = 0; i < 9; i++)
    {
        if (!notRepeat(board[i]))
            return false;
    } //row check
    for (int j = 0; j < 9; j++)
    {
        row.clear();
        for (int i = 0; i < 9; i++)
        {
            row.push_back(board[i][j]);
        }
        if (!notRepeat(row))
            return false;
    } //col check
    //area check  
    for (int kuai = 0; kuai < 9; kuai++)
    {
        vector<char> area;
        int row = kuai / 3;
        int col = kuai % 3;
        area.clear();
        for (int i = row * 3, count1 = 3; count1 > 0; count1--, i++)
        {
            for (int j = col * 3, count2 = 3; count2 > 0; count2--, j++)
            {
                area.push_back(board[i][j]);
            }
        }
        if (!notRepeat(area))
            return false;
    }
    return true;
}
int main()
{
    vector<char> x1 = { '5', '3', '.', '.', '7', '.', '.', '.', '.' };
    vector<char> x2 = { '6', '.', '.', '1', '9', '5', '.', '.', '.' };
    vector<char> x3 = { '.', '9', '8', '.', '.', '.', '.', '6', '.' };
    vector<char> x4 = { '8', '.', '.', '.', '6', '.', '.', '.', '3' };
    vector<char> x5 = { '4', '.', '.', '8', '.', '3', '.', '.', '1' };
    vector<char> x6 = { '7', '.', '.', '.', '2', '.', '.', '.', '6' };
    vector<char> x7 = { '.', '6', '.', '.', '.', '.', '2', '8', '.' };
    vector<char> x8 = { '.', '.', '.', '4', '1', '9', '.', '.', '5' };
    vector<char> x9 = { '.', '.', '.', '.', '8', '.', '.', '7', '9' };
    vector<vector<char>> shudu = {x1, x2, x3, x4, x5, x6, x7, x8, x9};
    if(isValidSudoku(shudu))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}