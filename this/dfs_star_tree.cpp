// #include<iostream>
// //链式前向星
// using namespace std;

// const int N = 1e5 + 10;
// int n, id;
// int h[N * 2];
// int e[N * 2], ne[N * 2];
// bool st[N * 2];
// void add(int a, int b)
// {
//     id++;
//     e[id] = b;
//     ne[id] = h[a];
//     h[a] = id;
// }

// void dfs(int u)
// {
//     cout << u << " ";
//     st[u] = true;
//     for(int i = h[u]; i; i = ne[i])
//     {
//         int v = e[i]; //孩子
//         if(!st[v])
//             dfs(v);
//     }
// }
// int main()
// {
//     cin >> n;
//     for(int i = 1; i < n; i++)
//     {
//         int a, b;
//         cin >> a >> b;
//         add(a, b);
//         add(b, a);
//     }

//     dfs(1);
//     return 0;
// }

#include<iostream>
using namespace std;
//
const int N = 1e5 + 10;
int e[N * 2], ne[N * 2], h[N], id;
int n;
bool st[N * 2];

void add(int a, int b)
{
    id++;
    e[id] = b;
    ne[id] = h[a];
    h[a] = id;
}

void dfs(int u)
{
    cout << u << " ";
    st[u] = true;
    for(int i = h[u]; i; i = ne[i])
    {
        int v = e[i];
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
        add(a, b);
        add(b, a);
    }
    dfs(1);
    return 0;
}