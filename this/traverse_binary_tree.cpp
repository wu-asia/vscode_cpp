#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int l[N], r[N];
int n;

void preorder(int u)
{
    cout << u << " ";
    if(l[u]) preorder(l[u]);
    if(r[u]) preorder(r[u]);
}

void inorder(int u)
{
    if(l[u]) inorder(l[u]);
    cout << u << " ";
    if(r[u]) inorder(r[u]);
}

void postorder(int u)
{
    if(l[u]) postorder(l[u]);
    if(r[u]) postorder(r[u]);
    cout << u << " ";
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
    }
    preorder(1);
    cout << endl;
    inorder(1);
    cout << endl;
    postorder(1);
    cout << endl;
    return 0;
}