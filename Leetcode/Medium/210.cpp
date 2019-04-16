#include "../common.h"

using namespace std;

// string int2str(int number)
// {
//     string res("");
//     while(number)
//     {
//         res = res + (char('0' + number % 10));
//         number /= 10;
//     }
//     return string(res.rbegin(), res.rend());
// }
// int str2int(string str)
// {
//     int res=0;
//     for (int i = 0; i < (int)str.length();i++)
//     {
//         res = res*10 + int(str[i] - '0');
//     }
//     return res;
// }
int count = 0;
void learn(int index, vector<int>& res, unordered_map<int,int>& hasLearned, const vector<int>& record,  unordered_map<int, vector<int>>& ump)
{   
    if(count >= 2*record.size())
        return;
    if(hasLearned.find(index)!=hasLearned.end())//学过
        return;
    count += 1;
    //以下都是没学过的
    if(record[index]==-1)//没依赖
    {
        res.push_back(index);
        hasLearned[index] = index;
        return;
    }
    if(record[index]==-2)//多个依赖
    {
        vector<int> tmp = ump[index];//需要学的依赖的列表
        for(auto num:tmp)
        {
            learn(num, res, hasLearned, record, ump);
        }
        res.push_back(index);
        hasLearned[index] = index;
        return;
    }
    //单个依赖
    if(hasLearned.find(record[index])!=hasLearned.end())//依赖学过
    {
        res.push_back(index);
        hasLearned[index] = index;
        return;
    }
    else//没学过
    {
        int tmp = record[index];
        learn(tmp, res, hasLearned, record, ump);
        res.push_back(index);
        hasLearned[index] = index;
        return;
    }
    
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) 
{
    vector<int> res;
    // unordered_map<int, int> record;
    vector<int> record(numCourses, -1);
    unordered_map<int, vector<int>> ump;
    unordered_map<int, int> hasLearned;
    for(auto pair : prerequisites)
    {
        cout << "first: " << pair.first << " second: " << pair.second << endl;
        if(record[pair.first]==-1)
            record[pair.first] = pair.second;
        else if(record[pair.first]==-2)
        {
            ump[pair.first].push_back(pair.second);
        }
        else
        {
            vector<int> tmp;
            tmp.push_back(record[pair.first]);
            record[pair.first] = -2;
            tmp.push_back(pair.second);
            ump[pair.first] = tmp;
        }
    }
    
    for(auto num:record)
        cout << num << " ";
    cout << endl;


    for (int i = 0; i < numCourses;i++)
    {
        learn(i, res, hasLearned, record, ump);
    }
    if(res.size()!=numCourses)
        return vector<int>();
    return res;
}
int main()
{
    vector<pair<int, int>> pre({{0, 1},{0,2},{1,2}});
    vector<int> res = findOrder(3, pre);
    for(auto num:res)
        cout << num << ' ';
    cout << endl;
    // cout << res.size() << endl;
    return 0;
}