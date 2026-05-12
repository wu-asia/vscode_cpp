#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base construction function" << endl;
    }
    ~Base()
    {
        cout << "Base destruction function" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        cout << "Son construction function" << endl;
    }
    ~Son()
    {
        cout << "Son desturction function" << endl;
    }
};

void test01()
{
    //Base b;
    //继承中的构造和顺序如下：
    //先构造父类，再次构造子类
    //析构的顺序与上述的相反
    Son s;
}
int main()
{
    test01();
    return 0;
}  