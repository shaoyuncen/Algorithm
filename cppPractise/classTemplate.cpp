#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// template <class T1, class T2>
// struct pair{

//     T1 first;
//     T2 second;
//     pair():first(T1()), second(T2()){}
//     pair(const T1& a, const T2& b):first(a), second(b){}

//     template<class U1, class U2>
//     pair(const pair<U1, U2>& p):first(p.first),second(p.second){}
// };

// class Base1{};
// class Derived1: public Base1{};
// class Base2{};
// class Derived2: public Base2{};
void getInt(int a){cout<<"Int"<<endl;}
void getDouble(double a){cout<<"Double"<<endl;}
void getString(string a){cout<<"String"<<endl;}
void getInt64(int64_t a){cout<<"Int64"<<endl;}

template <typename T>
void func(const T& a){
    if(is_same<T, int>::value)
        getInt(a);
    else if(is_same<T, int64_t>::value)
        getInt64(a);
    else
        return ;
}
// template <>
// void func<int>(const int& a){
//     getInt(a);
// }
// template<>
// void func<int64_t>(const int64_t& a){
//     getInt64(a);
// }
// template <>
// void func<double>(const double& a){
//     getDouble(a);
// }
template<>
void func<string>(const string& a){
    getString(a);
}

int main(int argc, char const *argv[])
{
    int a = 1; 
    int64_t b = 1;
    double c = 1.0;
    string d = "1";
    func(a);
    func(c);
    func(b);
    
    func(d);
    return 0;
}
