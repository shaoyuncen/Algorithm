#include <iostream>
using namespace std;
bool isPalindrome(string s)
{
    if (s.empty())
        return true;
    int size = s.size();
    int i = 0, j = size - 1;
    while (i < j)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            char temp_i = s[i] - ('A' - 'a');
            s[i] = temp_i;
        }
        if (s[j] >= 'A' && s[j] <= 'Z')
        {
            char temp_j = s[j] - ('A' - 'a');
            s[j] = temp_j;
        }
        while (s[i] > 'z' || s[i] < 'a')
            i++;
        while (s[j] > 'z' || s[j] < 'a')
            j--;
        if (s[i] != s[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
int main()
{
    string s = "0P";
    if(isPalindrome(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}