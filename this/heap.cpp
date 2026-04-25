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
        while(child + 1 <= n && heap[child + 1] > heap[child])
            child++;
        if(heap[parent] > heap[child]) 
            return;
        swap(heap[parent], heap[child]);
        
    }
}
int main()
{

    return 0;
}