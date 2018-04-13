// Given a column title as appear in an Excel sheet, return its corresponding column number.

//     For example :

//     A->1 B->2 C->3 ... Z->26 AA->27 AB->28
#include <math.h>
#include <iostream>
using namespace std;
int singleS(char s)
{
    if (s == ' ')
        return 0;
    else
        return s - 'A' + 1;
}
int titleToNumber(string s)
{
    int sum = 0;
    if (s.empty())
        return 0;
    else
    {
        unsigned int digit = s.size();
        for (unsigned int i = 0; i < s.size(); i++)
        {
            sum += (pow(26, digit - 1) * singleS(s[i]));
            digit--;
        }
    }
    return sum;
}
    int main()
    {
        string S = "AA";

        cout << titleToNumber(S) << endl;
        return 0;
    }