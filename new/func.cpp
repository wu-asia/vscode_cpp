#include<iostream>
using namespace std;

int func(int a, int b = 20, int c = 30)
{
    return a + b + c;
}
//函数申明有默认参数，则函数实现不能有默认参数
//函数申明和实现只能一个能有默认参数
//占位参数
//返回值类型  函数名（数据类型）{}

//目前阶段的占位参数 我们还用不到，后面课程会使用
//占位参数  还可以有默认参数
void func1(int a, int = 10)
{
    cout << "this is func" << endl;
}
int main()
{
    cout << func(10, 30) << endl;
    func1(10);
    return 0;
}