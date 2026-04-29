#include<iostream>
using namespace std;

//addition operator overload 

//member function overload addition
class Person
{
    friend ostream& operator<< (ostream& out, const Person& p);
public:
    Person(){this->A = 0, this->B = 0;}

    Person(int A, int B): A(A), B(B){}
    int A;
    int B;
    Person operator+(const Person& other) const
    {
        Person tmp;
        tmp.A = this->A + other.A;
        tmp.B = this->B + other.B;
        return tmp;
    }
    Person operator+(const int& num) const
    {
        Person tmp;
        tmp.A = this->A + num;
        tmp.B = this->B + num;
        return tmp;
    }
};

ostream& operator<< (ostream& out, const Person& p)
{
    out << p.A << ", " << p.B;
    return out;
}

void test01()
{
    Person p1;
    p1.A = 10;
    p1.B = 20;
    Person p2(20, 30);
    Person p3 = p1 + p2;
    cout << "p3 = " << p3 << endl;
    Person p4 = p2 + 1000;
    cout << "p4 = " << p4 << endl;
}
int main()
{
    test01();
    return 0;
}