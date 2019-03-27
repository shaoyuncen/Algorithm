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
Shape::Shape(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
Shape::~Shape()
{
}

int main()
{
    Shape sha(1);
    sha.print();
    return 0;
}