#include<iostream>
#include<queue>
using namespace std;
const int N = 1e5 + 10;
int n;
int l[N], r[N];

void bfs()
{
    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        if(l[u]) q.push(l[u]);
        if(r[u]) q.push(r[u]);
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    
    bfs();
    return 0;
}