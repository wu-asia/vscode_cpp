#include<iostream>
using namespace std;

class Base
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

//public inheritance

class Son : public Base
{
public:
    int d;
};

void test01()
{
    //父类中的所有非静态成员属性都会被继承
    //父类中的私有成员属性 是被编译器给隐藏了，因此是访问不到的，但是确实是被继承下去了
    
    cout << "sizeof Son = " << sizeof(Son) << endl;
}
int main()
{
    test01(); 
    return 0;
}