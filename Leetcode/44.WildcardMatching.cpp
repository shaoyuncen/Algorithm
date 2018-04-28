#include <iostream>
using namespace std;
bool isMatch(string s, string p)
{
    int is = 0, js = s.size() - 1, ip = 0, jp = p.size() - 1;
    while(ip <= jp)
    {
        while(p[ip] == s[is] || p[ip] == '?' )
        {
            ip++;
            is++;
        }
        if(p[ip] == '*' )
        {
            while (p[ip] == '*' && ip < jp)
                ip++;
            while ((p[jp] == s[js] || p[jp] == '?') && js > is && jp > ip)
            {
                jp--;
                js--;
            }
            while (s[js]!=p[ip] && is < js)
            {
                js--;
            }
            if(s[js] != p[ip])
                return false;
            else
            {
                is = ++js;
                ip++;
            }
            continue;
        }
        
    }
    if(is <= js)
        return false;
    else
        return true;
}
int main()
{
    string s = "acdcb";
    string p = "a*c?b";
    if(isMatch(s, p))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}