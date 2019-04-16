#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
#include<string>
using namespace std;

string ans,s,temp;

int main()
{
    int T;
    cin >> T;
    stack<char> Q;

        ans.clear();
        s.clear();
        temp.clear();
        cin >> s;
        int len = s.length();
        for(int i = 0; i < len; ++i)
        {
            if( s[i]=='(' || (s[i] >= '0' && s[i] <= '9') ) //遇到数字，直接入栈
            {
                Q.push(s[i]);
            }
            else if(s[i]>='a' && s[i] <= 'z')       //遇到字母
            {
                if(Q.top()>='0' && Q.top()<='9')    //栈顶元素是数字
                {
                    int num = Q.top() - '0';
                    Q.pop();
                    while(num--)
                        Q.push(s[i]);               //将字母压入栈num次
                }
                else
                    Q.push(s[i]);                   //没有数字，则直接将字母压入栈中
            }
            else if(s[i]==')')                      //遇到右括号
            {
                string temp;
                while(Q.top()!='(')
                {
                    temp.insert(temp.begin(),Q.top());  //存储括号内的字符串
                    Q.pop();
                }
                Q.pop();
                int num;                                //记录需要压入字符串的次数
                if( Q.empty() || !(Q.top()>='0'&&Q.top()<='9') )
                {
                    num = 1;
                }
                else
                {
                    num = Q.top() - '0';
                    Q.pop();
                }
                while(num--)                    //将括号内字符串压入num次
                {
                    for(int j = 0; j < temp.size(); ++j)
                        Q.push(temp[j]);
                }
            }
        }
        while(!Q.empty())       //将栈中字符全部存入结果ans[]中
        {
            ans.insert(ans.begin(),Q.top());
            Q.pop();
        }
        cout << ans << endl;
    

    return 0;
}