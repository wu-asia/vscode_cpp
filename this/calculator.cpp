#include<iostream>
#include<string>
using namespace std;

//普通写法
class Calculator
{
    public:
    int getResult(string oper)
    {
        if(oper == "+")
            return num1 + num2;
        else if(oper == "-")
            return num1 - num2;
        else if(oper == "*")
            return num1 * num2;
        return 0;
    }
    int num1, num2;
};

void test01()
{
    //创建计算机的对象
    Calculator cal;
    cal.num1 = 10;
    cal.num2 = 10;
    cout << cal.num1 << "+" << cal.num2 << "=" << cal.getResult("+") << endl;
    cout << cal.num1 << "-" << cal.num2 << "=" << cal.getResult("-") << endl;
    cout << cal.num1 << "*" << cal.num2 << "=" << cal.getResult("*") << endl;
}
int main()
{
    test01();
    return 0;
}
