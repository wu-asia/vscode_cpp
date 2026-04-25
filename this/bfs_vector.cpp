#include<iostream>
#include<queue>
#include<vector>

using namespace std;

const int N = 1e5 + 10;
int n;
vector<int> edges[N];
bool st[N];
void bfs()
{
    queue<int> q;
    q.push(1);
    st[1] = true;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(auto v : edges[u])
            if(!st[v])
            {
                q.push(v);
                st[v] = true;
            }
                
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    bfs();
    return 0;
}