#include <iostream>
#include <sstream>
#include <type_traits>
using namespace std;

template<typename T>
void func(const T& value){
    if(is_same<T, int>::value)
        cout << "int" << endl;
    else
        return;
}

int main(int argc, char const *argv[])
{
    func(1);   
    return 0;
}
