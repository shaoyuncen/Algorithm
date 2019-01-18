#include <iostream>
using namespace std;
bool isPalindrome(string s)
{
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
        if (!isalnum(s[start]))
            start++;
        else if (!isalnum(s[end]))
            end--;
        else
        {
            if (tolower(s[start++]) != tolower(s[end--]))
                return false;
        }
    }
    return true;
}
int main()
{
    string s = "Live on evasions ? No, I save no evil.";
    string s2 = ",.";
    if(isPalindrome(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
 
    return 0;
}