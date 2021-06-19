#include <bits/stdc++.h>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, curr_size, max_size;

public:
    Queue(int ds = 5) // Setting the default size of the Queue
    {
        arr = new int[ds];
        curr_size = 0;
        max_size = ds;
        front = 0;
        rear = max_size - 1;
    }

    bool empty()
    {
        return curr_size == 0;
    }

    bool full()
    {
        return curr_size == max_size;
    }

    void push(int data)
    {
        if (!full())
        {
            rear = (rear + 1) % max_size;
            arr[rear] = data;
            curr_size++;
        }
    }

    void pop()
    {
        if (!empty())
        {
            front = (front + 1) % max_size;
            curr_size--;
        }
    }

    int front_element()
    {
        return arr[front];
    }

    ~Queue()
    {
        if (arr != NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }
};

int main()
{
    Queue q;
    for (int i = 0; i < 7; i++)
    {
        q.push(i);
    }

    q.pop();
    q.pop();
    q.push(9);

    while (!q.empty())
    {
        cout << q.front_element() << " ";
        q.pop();
    }

    return 0;
}