#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
     int arr[10] = {
        1, 41, 23, 10, 11, 2, -1, 99, 14, 0 
    };
    vector<int> v;
    for(int i = 0; i < 10; i++)
        v.push_back(arr[i]);
    sort(v.begin(), v.end(), greater<int>());
    for(auto e : v)
        cout << e << " ";
    sort(v.begin(), v.end(), less<int>());
    cout << endl;
    for(auto e : v)
        cout << e << " ";
    return 0;
}