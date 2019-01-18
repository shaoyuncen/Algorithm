#include <iostream>
#include <vector>
using namespace std;
//http://www.cnblogs.com/grandyang/p/4475985.html 马拉车算法
//https://segmentfault.com/a/1190000003914228 马拉车算法详解
string longestPalindrome(string s)
{
    // Insert '#'
    string t = "$#";
    for (int i = 0; i < s.size(); ++i)
    {
        t += s[i];
        t += "#";
    }
    // Process t
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0;
    for (int i = 1; i < t.size(); ++i)
    {
        p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
        while (t[i + p[i]] == t[i - p[i]])
            ++p[i];
        if (mx - i <  p[i])
        {
            mx = i + p[i];
            id = i;
        }
        if (resLen < p[i])
        {
            resLen = p[i];
            resCenter = i;
        }
    }
    return s.substr((resCenter - resLen) / 2, resLen - 1);
}
int main()
{
    // string s1 = "12212";
    // cout << longestPalindrome(s1) << endl;
    // string s2 = "122122";
    // cout << longestPalindrome(s2) << endl;
    string s = "waabwswfd";
    cout << longestPalindrome(s) << endl;
    return 0;
}