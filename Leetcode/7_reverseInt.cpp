#include <iostream>
#include <math.h>
#ifndef INT_MIN
#define INT_MIN -pow(2, 31)
#endif
#ifndef INT_MAX
#define INT_MAX pow(2, 31) - 1
#endif
using namespace std;
int reverse(int x)
{
    if (x == INT_MIN)
        return 0;
    if (x < 0)
        return -reverse(-x);

    int rx = 0; // store reversed integer
    while (x != 0)
    {
        // check overflow
        if (rx > INT_MAX / 10)
            return 0;
        rx = rx * 10 + x % 10;
        x = x / 10;
    }
    return rx;
}
int main()
{
    int x = 123;
    int number = reverse(x);
    cout << number << endl;
    return 0;
}