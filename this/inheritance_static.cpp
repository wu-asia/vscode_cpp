#include<iostream>
using namespace std;

//静态成员变量，类内定义，类外初始化
class Base
{
public:
    static int a;
    static void func()
    {
        cout << "Base static void func()" << endl;

    }
    static void func(int num)
    {
        cout << "Base static void func(int num)" << endl;
    }
};

int Base::a = 100;
class Son : public Base
{
public:
    static int a;
    static void func()
    {
        cout << "Son static void func" << endl;
    }
};
int Son::a = 200;

//同名静态属性
void test01()
{
    //1.通过对象访问
    Son s;
    cout << "Son a = " << s.a << endl;
    cout << "Base a = " << s.Base::a << endl;

    //2.通过类名访问
    cout << "Son a = " << Son::a << endl;
    //第一个::代表通过类名方式访问 第二个::代表的是父类作用域下
    cout << "Base a = " << Son::Base::a << endl;
}
//同名静态的成员函数
void test02()
{
    //通过对象访问
    Son s;
    s.func();
    s.Base::func();
    //通过类名访问
    cout << "通过类名访问" << endl;
    Son::func();
    Son::Base::func();
    Son::Base::func(100);
}
int main()
{
    //test01();
    test02();
    return 0;
}