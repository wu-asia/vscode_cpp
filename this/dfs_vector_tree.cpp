// #include<iostream>
// #include<vector>
// using namespace std;
// const int N = 1e5 + 10;
// vector<int> edges[N];
// int n;
// bool st[N];

// void dfs(int u)
// {
//     cout << u << " ";
//     st[u] = true;
//     for(auto v : edges[u])
//     {
//         if(!st[v])
//             dfs(v);
//     }
// }
// int main()
// {
//     cin >> n;
//     //建树
//     for(int i = 1; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         edges[a].push_back(b);
//         edges[b].push_back(a);
//     }

//     dfs(1);
//     return 0;
// }

#include<iostream>
#include<vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> edges[N];
int n;
bool st[N];
void dfs(int u)
{
    cout << u << " ";
    st[u] = true;
    for(auto v : edges[u])
    {
        if(!st[v])
            dfs(v);
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

    dfs(1);
    return 0;
}