#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
using namespace std;

int dis(int x1, int y1, int x2, int y2)
{
    return int(sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}

int solu(const vector<pair<int,int>>& vec)
{
    int res = 0;
    deque<int> deq;
    vector<vector<int>> nums;
    int size = vec.size();
    for (int i = 0; i < size;i++)
    {
        vector<int> tmp;
        for (int j = 0; j < size;j++)
        {
            if(i==j)
            {
                tmp.push_back(-1);
                continue;
            }
            tmp.push_back(dis(vec[i].first, vec[i].second, vec[j].first, vec[j].second));
        }
        nums.push_back(tmp);
    }
    int now = 0;
    int nearest = -1;
    deq.push_back(0);
    while(deq.size()!=vec.size())
    {
        int idx = -1;
        int min = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if(nums[now][i] == -1)
                continue;
            if(nums[now][i] < min)
            {
                idx = i;
                min = nums[now][i];
            }
        }
        nums[now][idx] = -1;
        nums[idx][now] = -1;
        nearest = idx;
        if(deq.size()<=1)
        {
            deq.push_back(nearest);
            for (int i = 0; i < size;i++)
                nums[i][nearest] = -1;
        }
        else
        {
            int head = *deq.begin();
            int back = *deq.rbegin();
            if(nums[nearest][head] < nums[nearest][back])
                deq.push_front(nearest);
            else
                deq.push_back(nearest);
            for (int i = 0; i < size;i++)
                nums[i][nearest] = -1;
        }
        res += min;
        now = nearest;
    }
    int head = *deq.begin();
    int back = *deq.rbegin();    
    int dis1 = dis(vec[head].first, vec[head].second, 0, 0);
    int dis2 = dis(vec[back].first, vec[back].second, 0, 0);
    // cout << dis1 << ' ' << dis2 << endl;
    res = res + dis1 + dis2;
    return res;
}

int main()
{
    int count = 5;
    vector<pair<int,int>> vec;
    vec.push_back(pair<int,int>(200,0));
    vec.push_back(pair<int,int>(200,10));
    vec.push_back(pair<int,int>(200,50));
    vec.push_back(pair<int,int>(200,30));
    vec.push_back(pair<int,int>(200,25));

    int res = solu(vec);
    cout<<"result: "<<res<<endl;
    return 0;
}