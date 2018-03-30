#include <iostream>
using namespace std;
int Add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;          //得到没有进位的加法
        carry = (num1 & num2) << 1; //得到的“进位结果”
        num1 = sum;
        num2 = carry;
    } while (num2 != 0); //直到不再产生进位为止
    return num1;
}
int main()
{
    int nun1 = 18;
    int nun2 = 20;
    int sum = Add(nun1, nun2);
    cout << sum << endl;

    return 0;
}