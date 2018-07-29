class MyClass
{
public:
    MyClass();
    MyClass(int num);
    MyClass(MyClass &&) = default;
    MyClass(const MyClass &) = default;
    MyClass &operator=(MyClass &&) = default;
    MyClass &operator=(const MyClass &) = default;
    ~MyClass();

    int getA()
    {
        return a;
    }
private:
    int a;
};

MyClass::MyClass(int num)
{
    a = num;
}

MyClass::~MyClass()
{
}