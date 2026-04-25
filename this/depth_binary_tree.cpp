#include<iostream>
#include<algorithm>

using namespace std;
int n;
const int N = 1e6 + 10;
int l[N], r[N];

int depth(int root)
{
    if(root == 0) return 0;
    int left = depth(l[root]);
    int right = depth(r[root]);
    return max(left, right) + 1;
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    cout << depth(1) << endl;
    return 0;
}