#include<iostream>

using namespace std;


class Person
{
    public:
    void showClassName()
    {
        cout << "this is Person class" << endl;;
    }
    void showPersonAge()
    {
        if(this == nullptr)
        {
            return;
        }
        cout << "age = " << m_age << endl;
    }
    int m_age;
};

void test01()
{
    Person* p = nullptr;
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test01();
    return 0;
} 