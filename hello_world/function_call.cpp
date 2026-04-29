#include<iostream>
using namespace std;

class MyPrint
{
public:
    //重载函数调用运算符
    void operator() (string test)
    {
        cout << test << endl;
    }
};

class MyAdd
{
public:
    int operator() (int a, int b)
    {
        return a + b;
    }
};
void fuction(string test)
{
    cout << test << endl;
}
void test01()
{
    MyPrint functor;
    functor("hello world");
    fuction("hello world");
}

void test02()
{
    MyAdd haha;
    cout << haha(10, 20) << endl;
}

int main()
{
    test02();
    return 0;
}