#include<iostream>

using namespace std;

class Person
{
    public:
    Person(int age)
    {
        this->age = age;
    }
    Person& PersonAddAge(Person& p)
    {
        this->age += p.age;
        return *this;
    }
    int age;
};

void test01()
{
    Person p(18);
    cout << "p's age is :" << p.age << endl;
}

void test02()
{
    Person p1(18);
    Person p2(20);
    p1.PersonAddAge(p2).PersonAddAge(p2);
    cout << "p1's age is :" << p1.age << endl;
}
int main()
{
    test01();
    test02();
    return 0;
}