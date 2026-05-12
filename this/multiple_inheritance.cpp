#include<iostream>
using namespace std;

//多继承语法

class Base1
{
public:
    Base1()
    {
        a = 100;
    }
    int a;
};

class Base2
{
public:
    Base2()
    {
        a = 200;
    }
    int a;
};

//子类  需要继承Base1和Base2
//语法： class 子类 : 继承方式 父类1，继承方式 父类2
class Son : public Base1, public Base2
{
public:
    Son()
    {
        c = 300;
        d = 400;
    }
    int c, d;
};

void test01()
{
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl; 
    cout << "Base1 a = " << s.Base1::a << endl;
    cout << "Base2 a = " << s.Base2::a << endl;
}
int main()
{
    test01();
    return 0;
}