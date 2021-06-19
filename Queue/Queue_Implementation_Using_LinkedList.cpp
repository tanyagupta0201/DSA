#include <iostream>
#include <list>
using namespace std;

class Queue
{
    int cs;
    list<int> l;

public:
    Queue()
    {
        cs = 0;
    }

    // There is no full() function in linked lists as new nodes can be added

    bool empty()
    {
        return cs == 0;
    }

    void push(int data)
    {
        l.push_back(data);
        cs++;
    }

    void pop()
    {
        if (!empty())
        {
            l.pop_front(); // In Queue, we remove elements from front
            cs--;
        }
    }

    int front()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 10; i++)
    {
        q.push(i);
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}