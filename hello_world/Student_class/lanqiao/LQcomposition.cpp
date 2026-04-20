#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;
long long N;
int main()
{
    cin >> N;
    string s;
    cin >> s;
    unordered_map<char, long long> mp;
    for(int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    long long n = N - (N / 2);
    long long nl = mp['L'];
    long long nq = mp['Q'];
    long long ret = 0;
    if(nl > n || nq > n)
    {
        ret = max(nl, nq) * (N - max(nl, nq));
    }
    else
    {
        ret = N / 2 * (N - N / 2);
    }
    cout << ret << endl;
    return 0;
}