#include<queue>
#include<iostream>

using namespace std;
int n, m;
const int N = 1e4 + 10;
typedef long long LL;
LL a[N], b[N], c[N];
class node
{
public:
    LL f;
    LL num;
    LL x;
    bool operator> (const node& other) const
    {
        return f > other.f;
    }
};

priority_queue<node, vector<node>, greater<node>> heap;

LL calc(LL num, LL x)
{
    return a[num] * x * x + b[num] * x + c[num];
}
int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    LL x = 1;
    for(int i = 1; i <= n; i++)
    {
        heap.push({calc(i, x), i, x});
    }
    while(m--)
    {
        node tmp = heap.top();
        heap.pop();
        LL f = tmp.f, num = tmp.num, x = tmp.x;
        cout << f << " ";
        heap.push({calc(num, x + 1), num, x + 1});
    }
    return 0;
}