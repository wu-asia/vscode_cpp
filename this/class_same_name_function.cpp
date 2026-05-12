#include<iostream>
using namespace std;

//继承中同名的成员的处理
class Base
{
public:
    Base()
    {
        a = 100;
    }
    int a;
    void func()
    {
        cout << "Base funcJ" << endl;
    }
    void func(int num)
    {
        cout << "Base func(int num)" << endl;
    }
};

class Son : public Base
{
public:
    Son()
    {
        a = 200;
    }
    int a;
    void func()
    {
        cout << "son func" << endl;
    }
};

//同名的成员变量
void test01()
{
    Son s;
    cout << "Son a = " << s.a << endl;
    //如果通过子类对象，访问到父类中的同名成员属性
    //需要加上作用域
    cout << "Base a = " << s.Base::a << endl;
}

//同名的成员函数
void test02()
{
    Son s;
    //直接调用的是子类中的成员函数
    s.func();
    //如何调用父类中的同名函数
    s.Base::func(100);
    //如果子类中是出现父类中同名的成员函数,
    //子类中的同名成员函数会隐藏父类中所有的成员函数
    s.Base::func();

}

int main()
{
    test01();
    test02();
    return 0; 
}