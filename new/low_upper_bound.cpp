#include<iostream>
#include<set>

using namespace std;
int a[] = {10, 60, 20, 70, 80, 40, 100, 50};

int main()
{
    set<int> mp;
    for(auto x : a)
    {
        mp.insert(x);
    }
    //lower_bound 是大于等于这个数
    auto x = mp.lower_bound(20);
    //upper_bound 是大于这个数
    auto y = mp.upper_bound(20);
    cout << *x << " " << *y << endl;
    return 0;
}