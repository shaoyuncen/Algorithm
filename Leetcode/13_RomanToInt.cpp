#include <iostream>
#include <math.h>
using namespace std;
int romanToInt(string s)
{
    int number = 0;
    for (size_t i = 0, size = s.size() - 1; i < s.size(); i++)
    {
        int temp = s[i] - '0';
        number += (pow(10, size) * temp);
        size--;
    }
    return number;
}
int main()
{
    string s = "12345";
    cout << romanToInt(s) << endl;
    return 0;
}