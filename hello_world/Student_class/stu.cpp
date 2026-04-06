#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

static string FormatNumber(double value, int precision = 2)
{
    ostringstream oss;
    oss << fixed << setprecision(precision) << value;
    string s = oss.str();
    if (precision > 0 && s.find('.') != string::npos) {
        while (!s.empty() && s.back() == '0') s.pop_back();
        if (!s.empty() && s.back() == '.') s.pop_back();
    }
    return s;
}

class CStudent
{
private:
    string No;
    string Name;
    double DegChinese;
    double DegMaths;
    double DegEnglish;
    double Sum;
    static int Num;

public:
    CStudent()
        : No(""), Name(""), DegChinese(0), DegMaths(0), DegEnglish(0), Sum(0)
    {
        ++Num;
    }

    CStudent(const string& no,
             const string& name,
             double chinese,
             double maths,
             double english)
        : No(no),
          Name(name),
          DegChinese(chinese),
          DegMaths(maths),
          DegEnglish(english),
          Sum(chinese + maths + english)
    {
        ++Num;
    }

    ~CStudent()
    {
        --Num;
    }

    void SetData()
    {
        cout << "请输入学号 姓名 语文成绩 数学成绩 英语成绩: ";
        cin >> No >> Name >> DegChinese >> DegMaths >> DegEnglish;
        Sum = DegChinese + DegMaths + DegEnglish;
    }

    void Display() const
    {
        cout << No << "\t"
             << Name << "\t"
             << FormatNumber(DegChinese, 0) << "\t"
             << FormatNumber(DegMaths, 0) << "\t"
             << FormatNumber(DegEnglish, 0) << "\t"
             << FormatNumber(Average(), 2);
    }

    double Average() const
    {
        return (DegChinese + DegMaths + DegEnglish) / 3.0;
    }

    double Chinese() const { return DegChinese; }
    double Maths() const { return DegMaths; }
    double English() const { return DegEnglish; }
};

int CStudent::Num = 0;

class CStatistic
{
private:
    int Nums;
    double AveChinese;
    double AveMaths;
    double AveEnglish;
    CStudent StuArray[100];

public:
    CStatistic()
        : Nums(0), AveChinese(0), AveMaths(0), AveEnglish(0)
    {
    }

    CStatistic(int n)
        : Nums(n), AveChinese(0), AveMaths(0), AveEnglish(0)
    {
    }

    void SetStudents(int n)
    {
        Nums = n;
        for (int i = 0; i < Nums; ++i) {
            StuArray[i].SetData();
        }
        CalculateAverages();
    }

    static double Average(const CStudent students[], int n)
    {
        if (n <= 0) return 0.0;
        double total = 0.0;
        for (int i = 0; i < n; ++i) {
            total += students[i].Average();
        }
        return total / n;
    }

    void Sort()
    {
        sort(StuArray, StuArray + Nums, [](const CStudent& a, const CStudent& b) {
            return a.Average() > b.Average();
        });
    }

    void CalculateAverages()
    {
        if (Nums <= 0) {
            AveChinese = AveMaths = AveEnglish = 0.0;
            return;
        }

        double totalChinese = 0.0;
        double totalMaths = 0.0;
        double totalEnglish = 0.0;

        for (int i = 0; i < Nums; ++i) {
            totalChinese += StuArray[i].Chinese();
            totalMaths += StuArray[i].Maths();
            totalEnglish += StuArray[i].English();
        }

        AveChinese = totalChinese / Nums;
        AveMaths = totalMaths / Nums;
        AveEnglish = totalEnglish / Nums;
    }

    void Display() const
    {
        cout << "学号\t姓名\t语文\t数学\t英语\t平均分\t名次\n";
        for (int i = 0; i < Nums; ++i) {
            StuArray[i].Display();
            cout << "\t" << (i + 1) << "\n";
        }

        double classAverage = Average(StuArray, Nums);

        cout << "总评\t\t"
             << FormatNumber(AveChinese, 2) << "\t"
             << FormatNumber(AveMaths, 2) << "\t"
             << FormatNumber(AveEnglish, 2) << "\t"
             << FormatNumber(classAverage, 2) << "\n";
    }
};

int main()
{
    int count = 6;
    CStatistic* pStatistic = new CStatistic(count);

    cout << "请输入 " << count << " 名学生信息。\n";
    pStatistic->SetStudents(count);
    pStatistic->Sort();
    cout << "\n";
    pStatistic->Display();

    delete pStatistic;
    return 0;
}