#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool isNum(char s)
{
    return (s >= '0' && s <= '9') ? true : false;
}
int myAtoi(string str)
{
    long long int number = 0;
    if (str.empty())
        return 0;
    int index = 0;
//略过非空字符
    while (str[index] == ' ' && str[index] != '\0')
    {
        index++;
    }
//判断是否可以转换的字符串
    if (!isNum(str[index]) && str[index] != '-' && str[index] != '+')
        return 0;
//判断正负号
    bool judge = (str[index] == '-') ? false : true;
    if (str[index] == '-' || str[index] == '+')
        index++;
    if (!isNum(str[index]))
        return 0;
//把字符串转为数字
    while (str[index] != ' ' && isNum(str[index]) && str[index] != '\0')
    {
        int single = str[index] - '0';
        number = 10 * number + single;
        if (number > INT_MAX && judge == true)
            return INT_MAX;
        if (number > INT_MAX && judge == false)
            return INT_MIN;
        index++;
    }
    if (judge == true)
        return number;
    else
        return -number;
}
int main()
{
    string s1 = "2147483648";
    cout << myAtoi(s1) << endl;

    return 0;
}