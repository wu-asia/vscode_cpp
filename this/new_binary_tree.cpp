#include<iostream>
#include<unordered_map>
using namespace std;
const int N = 30;
char l[N], r[N];
int n;
unordered_map<char, int> mp;
void preorder(char u)
{
    cout << u;
    if(l[mp[u]] != '*') preorder(l[mp[u]]);
    if(r[mp[u]] != '*') preorder(r[mp[u]]);
}
int main()
{
    cin >> n;
    
    char first_node;
    for(int i = 1; i <= n; i++)
    {
        char node;
        cin >> node;
        if(i == 1) first_node = node;
        mp[node] = i;
        cin >> l[mp[node]] >> r[mp[node]];
    }
    preorder(first_node);
    return 0;
}