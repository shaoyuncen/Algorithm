#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int i = 42;
    int *pi = &i;
    cout << *pi << endl;
    *pi = *pi * *pi;
    cout << *pi << ' ' << i << endl;
<<<<<<< HEAD
    int x;
    cin >> x;
    cout << "x = " << x << endl;
=======
    cout<<"Some changes"<<endl;
    
>>>>>>> 3ded7e32ea35c367bc7ac71ef8164f90872d7a67
    return 0;
}
