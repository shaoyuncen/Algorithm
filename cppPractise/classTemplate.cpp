#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// template<typename T>
// class complex{
// public:
//     complex(T r = 0, T i = 0):re(r),im(i){}
//     complex& operator +=(const complex&);
//     T real() const {return re;}
//     T imag() const {return im;}
// private:
//     T re, im;
//     friend complex& _doapl(complex*, const complex&);
// };
void getInt(const int a){
    cout<<a<<endl;
}
void getInt64(const int64_t a){
    cout<<a<<endl;
}
void getString(const string& a){
    cout<<a<<endl;
}
void getDouble(const double a){
    cout<<a<<endl;
}




int main(int argc, char const *argv[])
{
    int a = 1;
    int64_t b = 2;
    double c = 1.0;
    string d = "11";
    func(a);
    func(b);
    func(c);
    func(d);
    return 0;
}
