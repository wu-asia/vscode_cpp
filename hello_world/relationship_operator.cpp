#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
    Person(string name, int age) : name(name), age(age);
    string name;
    int age;

    bool operator==(const Person& other) const 
    {
        return (this->name == other.name && this->age == other.age);
    }
    bool operator!=(const Person& other) const
    {
        return (this->name != other.name || this->age != other.age);
    }
};

void test01()
{
    Person p1("Tom", 18);
    Person p2("Tom", 18);

    if(p1 == p2)
    {
        cout << "p1 is equal to p2" << endl;
    }
    if(p1 != p2)
    {
        cout << "p1 is not equal to p2" << endl;
    }
}
int main()
{

    return 0;
}