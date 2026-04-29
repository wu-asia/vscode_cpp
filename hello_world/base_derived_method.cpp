#include<iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        a = 100;
    }
    int a;
};

class Son : public Base
{
public:
    Son()
    {
        a = 200;
    }
    int a;
};

void test01()
{
    Son s;
    cout << "a = " << s.a << endl;
}
int main()
{
    test01();
    return 0;
}