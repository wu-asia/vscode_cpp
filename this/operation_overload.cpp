#include<iostream>

using namespace std;



class Person
{
    public:
    //1.成员函数的重载加号
    // Person operator+(Person& p)
    // {
    //     Person tmp;
    //     tmp.A = this->A + p.A;
    //     tmp.B = this->B + p.B;
    //     return tmp;
    // }
    int A;
    int B;
};
//2.全局函数的重载加号
Person operator+ (const Person& p1, const Person& p2)
{
    Person tmp;
    tmp.A = p1.A + p2.A;
    tmp.B = p1.B + p2.B;
    return tmp;
}
void test01()
{
    Person p1;
    p1.A = 10;
    p1.B = 20;
    Person p2;
    p2.A = 20;
    p2.B = 30;
    Person p3 = p1 + p2;
    //Person类没有重载加号，所以编译器无法识别;
    cout << "p3.A = " << p3.A << endl;
    cout << "p3.B = " << p3.B << endl;
}
//加号的运算符重载


int main()
{
    test01();
    return 0;
}