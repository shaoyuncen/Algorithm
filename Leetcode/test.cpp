// unordered_map::erase
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

void countPrimes(int n)
{
    bool arrays[n+1];
    memset(arrays,true,sizeof(arrays));
    int count = 0;
    //筛选
    for (int i = 2; i < n; i++)
    {
        if (arrays[i] == false)
            continue;
        else if(arrays[i] == true)
        {
            cout<<i<<endl;
            count++;
            int temp = n - 1;
            while (temp > i)
            {
                if (temp % i == 0)
                    arrays[temp] = false;
                temp--;
            }
        }
    }

    cout << "result： " << count << endl;
}
int main()
{

    // countPrimes(10);

    return 0;
}