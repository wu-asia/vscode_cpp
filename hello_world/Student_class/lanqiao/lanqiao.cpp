#include<iostream>
#include<vector>

using namespace std;
int N, X, Y, T;
int main()
{
    cin >> T;
    
    vector<int> arr;
    while(T--)
    {
        cin >> N >> X >> Y;
        if(X > Y) arr.push_back(0);
        else arr.push_back(Y - X + 1);
    }
    for(auto e : arr)
        cout << e << endl;

    return 0;
}