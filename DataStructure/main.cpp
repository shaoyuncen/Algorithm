#include <iostream>
#include "./hpp/main.h"
using namespace std;
int main()
{
    MyClass my(10);
    int a = my.getA();
    cout << a << endl;
    return 0;
}