#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> heap;
     int arr[10] = {
        1, 41, 23, 10, 11, 2, -1, 99, 14, 0 
    };
    for(int i = 0; i < 10; i++)
    {
        heap.push(arr[i]);
    }
    while(heap.size())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
    return 0;
}