#include<iostream>
#include<string>
using namespace std;

string inorder, preorder;

void dfs(int l1, int r1, int l2, int r2)
{
    //递归出口
    if(l1 > r1 || l2 > r2) return;
    //函数体

    int p = l1;
    while(inorder[p] != preorder[l2])
        p++;
    
    dfs(l1, p - 1, l2 + 1, p - l1 + l2);
    dfs(p + 1, r1, p - l1 + l2 + 1, r2);
    cout << preorder[l2];
}
int main()
{
    cin >> inorder >> preorder;
    dfs(0, inorder.size() - 1, 0, preorder.size() - 1);
    return 0;
}