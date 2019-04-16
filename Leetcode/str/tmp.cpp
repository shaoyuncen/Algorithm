#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;


string solution(string input)
{
    string res="";
    int len = input.length();
    stack<char> kuohao;
    stack<int> dig;
    for (int i = 0; i < len;i++)
    {
        if(isalpha(input[i])&&dig.empty())//alpha
        {
            res += input[i];
            continue;
        }
        if(isdigit(input[i]))
        {
            if(dig.empty())
                dig.push(int(input[i]-'0'));
            else
            {
                int tmp = int(input[i] - '0');
                dig.push(tmp * dig.top());
                cout << "tmp: "<<tmp << endl;
            }
            continue;
        }
        if(isalpha(input[i])&&dig.empty()==false)
        {
            string tmp = "";

            while(isalpha(input[i]))
            {
                tmp += input[i];
                i++;
            }

            int count = dig.top();
            while(count>0)
            {
                res = res + tmp;
                count--;
            }
            i--;
            continue;
        }
        if(input[i] == '(' || input[i] =='{' || input[i]=='[')
        {
            kuohao.push(input[i]);
            continue;
        }
        if(input[i] == ')' || input[i] =='}' || input[i]==']')
        {
            kuohao.pop();
            dig.pop();
            continue;
        }
    }
    string result(res.rbegin(), res.rend());
    return result;
}


int main()
{
    string str;
    cin>>str;
    cout<<solution(str)<<endl;
    return 0;
}