#include<iostream>
using namespace std;

class Person
{
public:
    int* age;
    Person(int age)
    {
        this->age = new int(age);
    }
    Person(const Person& other)
    {
        this->age = new int(*(other.age));
    }
    Person& operator=(const Person& other)
    {
        if(this->age != nullptr)
        {
            delete this->age;
            this->age = nullptr;
        }
        this->age = new int;
        *(this->age) = *(other.age);
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
int main()
{
    return 0;
}