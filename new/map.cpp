#include<iostream>
#include<map>

using namespace std;

void print(map<string, int>& mp)
{
    for(auto& p : mp)
    {
        cout << p.first << " " << p.second << " ";
    }
    cout << endl;
}
int main()
{
    map<string, int> mp;
    mp.insert({"张三", 1});
    mp.insert({"李四", 2});
    mp.insert({"王五", 3});

    print(mp);
    return 0;
}