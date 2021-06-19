#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> v;

public:
    void push(T data)
    {
        v.push_back(data);
    }

    bool empty()
    {
        return v.size() == 0;
    }

    void pop()
    {
        if (!empty())
        {
            v.pop_back();
        }
    }

    T top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack<int> s;

    for (int i = 0; i < 5; i++)
    {
        s.push(i);
    }

    // Printing the content of the stack by popping each each element
    cout << "The contents of the stack are: " << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}