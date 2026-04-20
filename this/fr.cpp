//全局函数左右元
//类作为友元
//

#include<iostream>

using namespace std;

class Building
{
    public:
    Building()
    {
        //m_SettingRoom = "客厅"; 
        m_BedRoom = "卧室";

    }
    public:
    string m_SittingRoom;
    private:
    string m_BedRoom;
};

void goodGay(Building* building)
{
    cout << "好基友的全局函数 正在访问:" << building->m_SittingRoom << endl;
    //cout << "好基友的全局函数 正在访问:" << building->m_BedRoom << endl;
}

void test01()
{
    Building building;
    goodGay(&building);
}

int main()
{
    test01();
    return 0;
}