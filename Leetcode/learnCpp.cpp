#include <iostream>
using namespace std;
int main()
{
    int i = 42;
    int *pi = &i;
    cout << *pi << endl;
    *pi = *pi * *pi;
    cout << *pi << ' ' << i << endl;
    cout<<"Some changes"<<endl;
    
    return 0;
}