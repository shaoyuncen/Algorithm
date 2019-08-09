#include <iostream>
using namespace std;
class Base{
public:
    Base(){}
    virtual void print(){
        cout<<"I am Base"<<endl;
    }
    virtual ~Base(){}
};
class Son : public Base{
public:
    Son(){}
    virtual void print() override{
        cout<<"I am Son"<<endl;
    }
};
void func(Base& son)
{
    son.print();
}

int main(int argc, char const *argv[])
{
    Son aSon;
    func(aSon);
    
    return 0;
}
