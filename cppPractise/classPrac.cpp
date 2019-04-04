#include <iostream>

using namespace std;

class Shape
{
private:
    /* data */
  int x;
  int y;
  int z;

public:
    Shape(/* args */);
    Shape(int x = 10, int y = 5, int z = 1);

    ~Shape();
    Shape(const Shape &sha);//copy constructor.
    void print(){
        cout << x << ' ' << y << ' ' << z << endl;
    }
};

Shape::Shape(/* args */)
{
}
Shape::Shape(const Shape &a)
{
    x = 2 * a.x;
    y = 2 * a.y;
    z = 2 * a.z;
}
// Shape::Shape(int x, int y, int z)
// {//这是赋值操作，不是初始化操作，对于内置类型没差别，但是对于自定义类型效率会比较低
//   //赋值操作的初始化顺序是先调用default构造函数初始化，然后再赋值，那么default构造函数的一切作为就浪费了，
//   //并且对于const和reference类型，赋值操作是禁止的
//     this->x = x;
//     this->y = y;
//     this->z = z;
// }
Shape::Shape(int x, int y, int z) : x(x), y(y),z(z){}//用初始化列表方式初始化更好
Shape::~Shape()
{
}

int main()
{
    Shape sha(3,3,3);
    sha.print();
    return 0;
}