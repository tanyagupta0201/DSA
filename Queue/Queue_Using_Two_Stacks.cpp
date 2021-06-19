#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class Queue
{
    stack<T> s1, s2;

public:
    void push(T x)
    {
        s1.push(x);
    }

    void pop()
    {
        if (s1.empty())
        {
            return;
        }

        while (s1.size() > 1)
        {
            T element = s1.top();
            s2.push(element);
            s1.pop();
        }

        s1.pop();
        swap(s1, s2);
    }

    bool empty()
    {
        return size() == 0;
    }

    T top()
    {
        while (s1.size() > 1)
        {
            T element = s1.top();
            s2.push(element);
            s1.pop();
        }

        // 1 element in s1
        T element = s1.top();
        s1.pop();
        s2.push(element);

        swap(s1, s2);
        return element;
    }

    int size()
    {
        return s1.size() + s2.size();
    }
};

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}