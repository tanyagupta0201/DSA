#include <bits/stdc++.h>
using namespace std;

template <typename T, typename U>
class Stack
{
private:
    vector<T> v;
    vector<U> v2;

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
    Stack<char, int> s;

    for (int i = 65; i < 72; i++)
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