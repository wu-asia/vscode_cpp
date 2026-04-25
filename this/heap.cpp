#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;
int heap[N];
int n;

void up(int child)
{
    int parent = child / 2;
    while(parent >= 1 && heap[parent] < heap[child])
    {
        swap(heap[child], heap[parent]);
        child = parent;
        parent = child / 2;
    }
}

void down(int parent)
{
    int child = parent * 2;
    while(child <= n)
    {
        if(child + 1 <= n && heap[child + 1] > heap[child])
            child++;
        if(heap[parent] > heap[child])
            return;
        swap(heap[parent], heap[child]);
        parent = child;
        child = parent * 2;
    }
}

void push(int ele)
{
    heap[++n] = ele;
    up(n);
}

void pop()
{
    swap(heap[1], heap[n]);
    n--;
    down(1);
}

int top()
{
    return heap[1];
}

int size()
{
    return n;
}

int main()
{
    int arr[10] = {
        1, 41, 23, 10, 11, 2, -1, 99, 14, 0 
    };
    for(int i = 0; i < 10; i++)
    {
        push(arr[i]);
    }
    while(size())
    {
        cout << top() << " ";
        pop();
    }
    return 0;
}