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
//利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator
{
public:
    virtual int getResult()
    {
        return 0;
    }
    int num1, num2;
};
//加法的计算器的类
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 + num2;
    }
};
//减法的计算器
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 - num2;
    }
};

class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return num1 * num2;
    }
};

void test02()
{
    //多态使用条件
    //父类指针或者引用指向子类对象
    //加法运算
    AbstractCalculator* abc = new AddCalculator;
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->num1 << "+" << abc->num2 << "=" << abc->getResult() << endl;
    delete abc;

    //减法
    abc = new SubCalculator;
    abc->num1 = 100;
    abc->num2 = 20;
    cout << abc->num1 << "-" << abc->num2 << "=" << abc->getResult() << endl;
    delete abc;
    //乘法
    abc = new MulCalculator;
    abc->num1 = 20;
    abc->num2 = 30;
    cout << abc->num1 << "*" << abc->num2 << "=" << abc->getResult() << endl;
    delete abc;
}
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
    test02();
    return 0;
}
