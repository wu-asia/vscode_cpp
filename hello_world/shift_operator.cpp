#include<iostream>
using namespace std;

class Person
{
    friend ostream& operator<< (ostream& out, const Person& self);

public:
    Person(int a, int b):a(a), b(b) {}

private:
    int a;
    int b;
};

ostream& operator<< (ostream& out, const Person& self)
{
    cout << "a = " << self.a << ", b = " << self.b;
    return out;
}
void test01()
{
    Person p(10, 20);

    cout << p << endl;
}
int main()
{
    test01();
    return 0;
}