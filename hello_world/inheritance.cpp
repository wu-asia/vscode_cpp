#include<iostream>

using namespace std;

class Java
{
public:
    void header()
    {
        cout << "headers, public class, login, " << endl;
    }
    void footer()
    {
        cout << "help center, cooperation and communication, station map" << endl;
    }
    void left()
    {
        cout << "java, python, c++" << endl;
    }
    void content()
    {
        cout << "java subject videos" << endl;
    }
};

//make inheritance come true

class BasePage
{
public:
    void header()
    {
        cout << "homepage, public classes, login, register...(public header)" << endl;
    }
    void footer()
    {
        cout << "help cnter, communication and cooperation, station map...(public footer)" << endl;
    }
    void left()
    {
        cout << "Java, Python, CPP..." << endl;
    }
};

//java page
class Java: public BasePage
{
public:
    void content()
    {
        cout << "java subject videos" << endl;
    }
};
//python page
class Python : public BasePage
{
    void content()
    {
        cout << "python subject videos" << endl;
    }
}
//cpp page

class Cpp : public BasePage
{
public:
    void content()
    {
        cout << "cpp subject videos" << endl;
    }
}

// the advantage of inheritance: decreasing the repeated codes
//
void test01()
{
    cout << "java videos download upside" << endl;
    Java ja;
    ja.header();
    ja.footer();
    ja.left();
    ja.content();
}

int main()
{
    test01();
    return 0;
}