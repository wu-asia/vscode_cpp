#include<iostream>
#include<string>
#include<iomanip> //使用setw()函数
using namespace std;

class CStudent
{
    public:
    CStudent();
    CStudent(string no, string name, double Chinese, double Math, double English);
    void SetData();
    void Display();
    float Average();
    ~CStudent();
    private:
    string No;
    string Name;
    double* Deg;//成绩数组，用于存储语数英三门的成绩
    double Sum;
    int Num;
    const int sub_num = 3;// 用于对于成绩门数的定义（常量）
};

CStudent::CStudent()//无参数构造函数
{
    Deg = new double[sub_num];
    Deg[0] = 0.0;
    Deg[1] = 0.0;
    Deg[2] = 0.0;
    No = "";
    Name = "";
    Sum = 0.0;
    Num = 1;
}
//有参数的构造函数
CStudent::CStudent(string no, string name, double Chinese, double Math, double English)
{
    Deg = new double[sub_num];//申请内存空间
    No = no;
    Name = name;
    Deg[0] = Chinese;
    Deg[1] = Math;
    Deg[2] = English;
    Sum = Deg[0] + Deg[1] + Deg[2];
    Num = 1;
}
void CStudent::SetData()
{
    cin >> No >> Name >> Deg[0] >> Deg[1] >> Deg[2];
    Sum = Deg[0] + Deg[1] + Deg[2];
}

CStudent::~CStudent()
{
    delete[] Deg;
    Deg = nullptr;
}

void CStudent::Display()
{
    cout << setw(10) << No 
    << setw(10) << Name
    << setw(10) << Deg[0]
    << setw(10) << Deg[1]
    << setw(10) << Deg[2]
    << setw(10) << Average()
    << endl;
}

float CStudent::Average()
{
    return Sum / 3;
}
int main()
{
    CStudent s1;
    s1.SetData();
    s1.Display();
    return 0;
}