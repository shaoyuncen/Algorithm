#include <iostream>
#include <string>
#include <type_traits>

using namespace std;
void print(string str)
{
    cout<<str<<endl;
}
template <typename T>
void addObject( const T & value){
	if (std::is_same<T, int>::value)
		print("int");
	else if (std::is_same<T, double>::value)
		print("double");
	else if (std::is_same<T, std::string>::value)
		print("string");
	else if (std::is_same<T, int64_t>::value)
		print("int64_t");
	else
		return;
}
int main(int argc, char const *argv[])
{
    int a = 1;
    int64_t b = 11;
    string c = "aaa";
    double d = 1.1;
    addObject(a);
    
    addObject(b);

    addObject(c);

    addObject(d);


    return 0;
}
