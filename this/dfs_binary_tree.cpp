#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n;
int l[N], r[N];

void preorder_dfs(int u)
{
    // root left right
    cout << u << " ";
    if(l[u]) preorder_dfs(l[u]);
    if(r[u]) preorder_dfs(r[u]);
}

void inorder_dfs(int u)
{
    //left root right
    if(l[u]) inorder_dfs(l[u]);
    cout << u << " ";
    if(r[u]) inorder_dfs(r[u]);
}

void postorder_dfs(int u)
{
    //left right root
    if(l[u]) postorder_dfs(l[u]);
    if(r[u]) postorder_dfs(r[u]);
    cout << u << " ";
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    preorder_dfs(1);
    cout << endl;
    inorder_dfs(1);
    cout << endl;
    postorder_dfs(1);
    cout << endl;
    return 0;
}