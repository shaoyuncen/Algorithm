#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s)
{
    stack<char> stk;
    int start = 0, size = s.size();
    for (; start < size; start++)
    {
        if (s[start] == '(' || s[start] == '{' || s[start] == '[')
            stk.push(s[start]);
        else if (s[start] == ')' || s[start] == '}' || s[start] == ']')
        {
            if(stk.empty())
                return false;
            else if (s[start] == ')' && stk.top() == '(')
                stk.pop();
            else if (s[start] == '}' && stk.top() == '{')
                stk.pop();
            else if (s[start] == ']' && stk.top() == '[')
                stk.pop();
            else
                return false;
        }
        else
            continue;
    }
    if (stk.empty())
        return true;
    else
        return false;
}
int main()
{
    string s = "{{[[]}}";
    string s2 = "]";
    if (isValid(s2))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}