#include<iostream>

using namespace std;

class Person
{
    public:
    Person(int age)
    {
        this->age = new int(age);
    }
    ~Person()
    {
        if(age != nullptr)
        {
            delete age;
            age = nullptr;
        }
    }
    //overload equal operator
    Person& operator=(Person& p)
    {
        if(age != nullptr)
        {
            delete age;
            age = nullptr;
        }

        age = new int(*p.age);
        //return self
        return *this;
    }
    //private:
    int* age;
};

void test01()
{
    Person p1(18);
    cout << "p1 = " << *p1.age << endl;
    
    Person p2(20);
    p2 = p1;
    cout << "p2 = " << *p2.age << endl;
}
int main()
{
    test01();
    return 0;
}