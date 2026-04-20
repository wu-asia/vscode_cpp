#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<<(ostream& cout, Person& p);
public:
    Person(int A, int B) 
    {
        this->A = A;
        this->B = B;
    }
private:
    //利用成员函数重载 左移运算符
    // void operator<< (Person& p)
    // {

    // }
    int A;
    int B;
};

//只能利用全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p)
{
    cout << "A=" << p.A << " , " << "B=" << p.B;
    return cout;
}
void test01()
{
    Person p(10, 10);
    // p.A = 10;
    // p.B = 20;
    cout << p << endl;
}
int main()
{
    test01();
    return 0;
}