#include<iostream>
using namespace std;

class MyInter
{
    friend ostream& operator << (ostream& out, const MyInter& self);
    friend MyInter& operator++(MyInter& self);
    friend MyInter operator++(MyInter& self, int);
public:
    MyInter()
    {
        this->num = 0;
    }
private:
    int num;
};

ostream& operator << (ostream& out, const MyInter& self)
{
    out << self.num;
    return out;
}

MyInter operator++(MyInter& self, int)
{
    MyInter tmp = self;
    self.num++;
    return tmp;
}
MyInter& operator++(MyInter& self)
{
    self.num++;
    return self;
}
void test01()
{
    MyInter myint;

    cout << ++myint << endl;
}
int main()
{
    test01();
    return 0;
}