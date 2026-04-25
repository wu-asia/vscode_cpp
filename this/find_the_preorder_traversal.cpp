#include<iostream>
#include<string>
using namespace std;

string inorder, postorder;

void dfs(int l1, int r1, int l2, int r2)
{
    //递归出口
    if(l1 > r1 || l2 > r2) return;
    //函数体
    cout << postorder[r2];
    int p = l1;
    while(inorder[p] != postorder[r2]) p++;
    dfs(l1, p + 1, l2, p - l1 + l2 - 1);
    dfs(p + 1, r1, p - l1 + l2, r2 - 1);
}
int main()
{
    cin >> inorder >> postorder;
    dfs(0, inorder.size() - 1, 0, postorder.size() - 1);
    return 0;
}