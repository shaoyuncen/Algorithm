// unordered_map::erase
#include <iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;

void countPrimes(int& n)
{
    for(int i = 1; i < 5; i++)
    {
        n *= i;
    }
}
int main()
{
    int n = 10;
    countPrimes(n);
    cout<<n<<endl;
    auto a = n + 1;
    cout<<a<<endl;


    return 0;
}