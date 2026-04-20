//全局函数作友元
//类作友元
//成员函数作友元

#include<iostream>
using namespace std;

class Building
{
    //
    friend void goodGay(Building* building);
    public:
    Building()
    {
        m_sittingRoom = "客厅";
        m_BedRoom = "卧室";
    }
    string m_sittingRoom;//客厅
    private:
    string m_BedRoom;//卧室
};

//全局函数
void goodGay(Building* building)
{
    cout << "好基友的全局函数 正在访问:" << building->m_sittingRoom << endl;
    cout << "好基友的全局函数 正在访问:" << building->m_BedRoom << endl;
}

int main()
{
    Building building;
    goodGay(&building);
    return 0;
}