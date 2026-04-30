#include<iostream>
#include<set>
#include<string>

using namespace std;

int a[] = {10, 60, 20, 70, 80, 40, 100, 50};

int main()
{
    //set 不能存储相同的元素
    //multiset 可以存储相同的元素
    set<int> mp;
    for(auto x : a)
    {
        mp.insert(x);
    }
    for(auto x : mp)
    {
        cout << x << " ";
    }
    cout << endl;
    if(mp.count(1)) cout << "1" << endl;
    if(mp.count(99)) cout << "99" << endl;
    if(mp.count(30)) cout << 30 << endl;
    if(mp.count(10)) cout << 10 << endl;

    mp.erase(30);
    mp.erase(10);
    if(mp.count(30)) cout << 30 << endl;
    else cout << "no : 30" << endl;
    if(mp.count(10)) cout << 10 << endl;
    else cout << "no : 10" << endl;
    return 0;
}