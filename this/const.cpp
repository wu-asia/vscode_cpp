#include<iostream>

using namespace std;

class Person
{
    public:
    //this 指针的本质 是指针常量，指向自己的地址 指针的指向是不可修改的
    void showPerson() const
    {
        this->m_A = 100;
        
    }
    mutable int m_A;
};

void test01()
{
    Person p;
    p.showPerson(); 
}