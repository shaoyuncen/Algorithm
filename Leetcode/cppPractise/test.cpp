#include <iostream>

using namespace std;
// #define max(a,b) (a>b? a: b) //warning
void func()
{
    static int a = 1;
    cout << a++ << endl;//when function cal over, variable a won`t be destroyed. and variable a saved in static storage.
}
// inline max function
template <class T>
const T &max(const T &a, const T &b) { return a > b ? a : b; }
int main()
{


    // func();//1
    // func();//2

    // enum
    // {
    //     NUM_TURNS = 5
    // };
    // int size = 5;
    // int scores[NUM_TURNS];
    // cout << NUM_TURNS;
    return 0;
}