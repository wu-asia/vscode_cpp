#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
long long T, N;
int main()
{
    cin >> T;
    string ans;
    while(T--)
    {
        cin >> N;
        vector<long long> arr(N);
        long long sum = 0;
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());
        if(arr[N - 1] * 5 <= sum && sum % 5 == 0) ans.push_back('T');
        else ans.push_back('F');
    }
    for(char e : ans)
        cout << e << endl;
    return 0;
}
// A B C  D  E  F  G  H 
// 5 5 10 10 15 15 20 20
// 5 0 3  3  