#include<iostream>
using namespace std;

class MyInteger
{
    friend ostream& operator<<(ostream& out, const MyInteger& myint);
    public:
    MyInteger(): num(0) {}
    //overload prefix++ operator
    MyInteger& operator++()
    {
        num++;
        return *this;
    }
    //overlaod suffix++ operator
    MyInteger operator++(int)
    {
        //first
        MyInteger tmp = *this;
        this->num++;
        return tmp;
    }
    private:
    int num;
    
    
};
//cout operator overload
ostream& operator<<(ostream& out, const MyInteger& myint)
{
    out << myint.num << endl;
    return out;
}
void test01()
{
    MyInteger myint;
    cout << myint << endl;
    cout << ++myint << endl;
}
int main()
{
    test01();
    return 0;
}