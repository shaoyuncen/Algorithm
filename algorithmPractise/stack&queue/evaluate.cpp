//(3+4)*14
#include <iostream>
#include <stack>

using namespace std;
bool isRight(char ch)
{
    return ch==')' || ch==']' || ch=='}';
}
bool isLeft(char ch)
{
    return ch=='(' || ch=='[' || ch=='{';
}
bool compare(char ch1, char ch2)
{   
    //ch1<ch2 false, ch1>=ch2 true
    if((ch1 == '-' || ch1 == '+')&&(ch2=='*'||ch2=='/'))
        return false;
    else
        return true;
}
int eval(int oper1, int oper2, char opera)
{
    int result;
    switch(opera)
    {
        case '+': 
            result = oper1 + oper2;
            break;
        case '-':
            result = oper1 - oper2;
            break;
        case '*':
            result = oper1 * oper2;
            break;
        case '/':
            result = oper1 / oper2;
            break;
    }
    return result;
}
int evaluate(string input)
{
    stack<int> num;
    stack<char> sig;

    //去括号
    for(int i=0;i<input.length();++i)
    {
        if(isdigit(input[i]))//数字
            num.push(input[i]-'0');
        else
        {//符号
            if(isRight(input[i]))//右括号
            {
                while(!isLeft(sig.top()))
                {
                    int oper2 = num.top();
                    num.pop();
                    int oper1 = num.top();
                    num.pop();
                    char signal = sig.top();
                    sig.pop();
                    int tmp = eval(oper1, oper2, signal);
                    num.push(tmp);
                }
                sig.pop();//pop left
            }
            else
                sig.push(input[i]);
        }
    }

    char flag = sig.top();
    sig.pop();
    while(!sig.empty())
    {
        if(compare(flag, sig.top()))//优先级高于等于则为true
        {
            int oper2 = num.top();
            num.pop();
            int oper1 = num.top();
            num.pop();
            int tmp = eval(oper1, oper2, flag);
            num.push(tmp);
            flag = sig.top();
            sig.pop();
        }
        else
        {
            int oper2 = num.top();
            num.pop();
            int oper1 = num.top();
            num.pop();
            int tmp = eval(oper1, oper2, sig.top());
            num.push(tmp);
            sig.pop();
        }
    }
    int oper2 = num.top();
    num.pop();
    int oper1 = num.top();
    num.pop();
    return eval(oper1, oper2, flag);
}
int main(int argc, char const *argv[])
{
    string express("(3+4)*8");
    int result = evaluate(express);
    cout<<"result: "<< result << endl;

    return 0;
}