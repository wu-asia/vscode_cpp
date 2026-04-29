#include<iostream>
using namespace std;

class Person
{
    public:
    Person(int age)
    {
       this->age = new int(age);
    }
    Person(const Person& other)
    {
        this->age = new int;
        *(this->age) = *(other.age);
    }
    int* age;
    Person& operator=(Person& other)
    {
        if(this->age != nullptr)
        {
            delete this->age;
            this->age = nullptr;
        }
        this->age = new int(*(other.age));
        return *this;
    }
    ~Person()
    {
        if(this->age != nullptr)
        {
            delete this->age;
            this->age = nullptr;
        }   
    }
};

void test01()
{
    Person p1(18);
    Person p2(20);
    p2 = p1; //assignment operation
    cout << "p1's age is:" << *(p1.age) << endl;
    cout << "p2's age is:" << *(p2.age) << endl;

}
int main()
{
    test01();
    return 0;
}