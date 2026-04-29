#include<iostream>
using namespace std;
//inheritance method

//public inheritance
class Base1
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Son1 : public Base1
{
public:
    void func()
    {
        a = 10;//public
        b = 10;//protected
    }
};

void test01()
{
    Son1 s1;
    s1.a = 100;
    //s1.b = 100;
}
//protected inheritance
class Base2
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        a = 100; //protected
        b = 100; //protected
    }
};

void test02()
{
    Son2 s1;
    //s1.a = 100;
}

//private inheritance
class Base3
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Son3 : private Base3
{
public:
    void func()
    {
        a = 100;//private
        b = 100;//private
        //c = 10;
    }
};

class GrandSon3 : public Son3
{
public:
    void func()
    {
        a = 10;
        b = 20;
        c = 20;
    }
}
void test03()
{
    Son3 s1;
    // s1.a;
    // s1.b;
}
int main()
{

    return 0;
}