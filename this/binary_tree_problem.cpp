#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
const int N = 110;
vector<int> edges[N];
int fa[N]; //fa[i] 表示 i 的父节点
int dest[N]; //dest[i] 表示向上爬时所有的结点到起始点的距离，表示 i 到x的最短距离
int n;

int dfs(int u)
{
    if(u == 0) return 0;

    int ret = 0;
    for(auto v : edges[u])
    {
        ret = max(dfs(v), ret);
    }
    return ret + 1;
}

int bfs()
{
    queue<int> q;
    q.push(1);
    int ret = 0;
    while(q.size())
    {
        int sz = q.size();
        ret = max(ret, sz);
        while(sz--)//将这一层的所有的结点都出队
        {
            int u = q.front();
            q.pop();
            for(auto v : edges[u])
            {
                q.push(v);
            }
        }
    }
    return ret;
}
int main()
{
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        //u -> v
        edges[u].push_back(v);
        fa[v] = u;
    }
    int x, y;
    cin >> x >> y;
    cout << dfs(1) << endl;

    cout << bfs() << endl;
    //计算x到1中间经历的所有点的距离是多少
    while(x != 1)
    {
        dest[fa[x]] = dest[x] + 1;
        x = fa[x];
    }
    
    int len = 0;
    //dest[y] 等于零表示还没有走过这条路线
    while(y != 1 && dest[y] == 0)
    {
        y = fa[y];
        len++;
    }

    cout << dest[y] * 2 + len << endl;

    return 0;
}