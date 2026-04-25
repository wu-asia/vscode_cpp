#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e6 + 10;
int sz;
long long heap[N];

void up(int child)
{
    int parent = child / 2;
    while(parent >= 1 && heap[parent] > heap[child])
    {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }
}

void down(int parent)
{
    int child = parent * 2;
    while(child <= sz)
    {
        if(child + 1 <= sz && heap[child + 1] < heap[child])
            child++;
        if(heap[parent] < heap[child])
            return;
        swap(heap[parent], heap[child]);
        parent = child;
        child = parent * 2;
    }
}

void push(int x)
{
    heap[++sz] = x;
    up(sz);
}

void pop()
{
    swap(heap[1], heap[sz]);
    sz--;
    down(1);
}

int size()
{
    return sz;
}

int top()
{
    return heap[1];
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            int x;
            cin >> x;
            push(x);
        }
        else if(op == 2)
        {
            cout << top() << endl;
        }
        else
        {
            pop();
        }
    }
    return 0;
}