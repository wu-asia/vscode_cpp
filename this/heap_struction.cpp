#include<iostream>
#include<queue>

using namespace std;

int arr[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0 };

class node
{
    public:
    int a, b, c;
    bool operator< (const node& other) const
    {
        return b < other.b;
    }
    bool operator> (const node& other) const
    {
        return b > other.b;
    }
};

ostream& operator<< (ostream& out, const node& self)
{
    out << self.a << " " << self.b << " " << self.c;
    return out;
}
void test1()
{
    priority_queue<node, vector<node>, less<node>> heap;
    for(int i = 1; i <= 5; i++)
    {
        heap.push({i + 10, i + 1, i + 2});
    }
    while(heap.size())
    {
        cout << heap.top() << endl;
        heap.pop();
    }
}
int main()
{
    test1();
    return 0;
}