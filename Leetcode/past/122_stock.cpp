#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int profits = 0;

    for (int i = 0, j = 1; j < (int)prices.size(); j++)
    {
        if (prices[j] >= prices[i])
        {
            profits += (prices[j] - prices[i]);
            i = j;
        }
        else
        {
            i = j;
        }
    }
    return profits;
}

int main()
{
    vector<int> nums = {2, 1, 2, 0, 1};
    int count = maxProfit(nums);
    return 0;
    cout << count << endl;
}