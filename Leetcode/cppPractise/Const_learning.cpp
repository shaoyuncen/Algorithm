#include <iostream>

using namespace std;
//const practise
//named bxxx are all error, named axxx are all true.
//记忆方法：指针p翻译成p is a   * 翻译成point to
//记忆方法2： const *，则指针普通，* const，指针为常量, const * const 指针和内容都是常量, 数据类型T必须在*前面，但位置不影响。
int main()
{
    const int a = 10;
    // b = 20;  //error， 常量不可修改
    // const int bb;  //error  常量必须初始化
    int aa = 10;
    int bb = 11;
    const int aaa = aa; //true, 非const 初始化 const
    const int aaaa = aaa;//true   const 初始化 const

    // int &bbb = 2; //error  右值不可用于非const 初始化
    // int &bbbb = aa * 2;//error  aa*2表达式仍然是个右值
    int* const p1 = &aa; //p1 is a const point to int 指向整型的  常量指针，指向不能变
    *p1 = 10;//true
    // p1 = &bb;//error 指向不能变
    int const *p2 = &aa; //p2 is a point to const int 指向常量的整型指针，指向内容不能变
    // cout << p2 << endl;//地址0x61fe38   内容：aa变量的值
    p2 = &bb;//true
    // cout << p2 << endl;//地址Ox61fe3c   内容：bb变量的值

    int const* const p3 = &aa;//p3 is a const point to int const 指向内容和地址都不能变
    cout <<"p3 offset: "<< p3 <<"  value: "<<*p3<< endl;
    const int* const p5 = &aa;//p5 is a const point to const int 指向内容和地址都不能变
    const int* p4 = &bb; //p4 is a int point to const 指向常量的整型指针，指向内容不变
    cout <<"p4 offset: "<< p4 <<"  value: "<<*p4<< endl;
    p4 = &bb;
    
   

    return 0;
}