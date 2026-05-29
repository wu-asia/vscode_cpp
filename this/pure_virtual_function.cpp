#include<iostream>

using namespace std;
//纯虚函数和抽象类
class Base
{
public:
    //纯虚函数
    //只有有一个纯虚函数，这个类成为抽象类
    //抽象类的特点
    //1、无法实例化对象
    //2、抽象类中的子类必须要重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    
};
void test01()
{
    Base b; //抽象类是无法实例化的
    new Base; //抽象类是无法实例化的
}
int main()
{

    return 0;
}