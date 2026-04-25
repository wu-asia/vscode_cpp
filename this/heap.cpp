// #include<iostream>
// using namespace std;

// const int N = 1e6 + 10;
// //堆的实现

// int n;
// int heap[N];
// //向上调整算法
// void up(int child)
// {
//     int parent = child / 2;
//     while(parent >= 1 && heap[child] > heap[parent])
//     {
//         swap(heap[child], heap[parent]);
//         child = parent;
//         parent = child / 2;
//     }
// }

// void down(int parent)
// {
//     int child = parent * 2;
//     while(child <= n)
//     {
//         //找出最大的孩子
//         if(child + 1 <= n && heap[child + 1] > heap[child])
//             child++;
//         if(heap[parent] >= heap[child]) return;

//         swap(heap[parent], heap[child]);
//         parent = child;
//         child = parent * 2;
//     }
// }
// int main()
// {

//     return 0;
// }


#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int heap[N];
int n;

//向上调整算法(大根堆)
void up(int child)
{
    int parent = child / 2;
    while(parent >= 1 && heap[parent] < heap[child])
    {
        swap(heap[parent], heap[child]);
        child = parent;
        parent = child / 2;
    }
}

//向下调整算法(大根堆)
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

//插入元素
void push(int ele)
{
    heap[++n] = ele;
    up(n);
}
//删除元素
void pop()
{
    swap(heap[1], heap[n]);
    n--;
    down(1);
}

//返回堆顶元素
int top()
{
    return heap[1];
}

//堆的大小
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