#include <bits/stdc++.h>
using namespace std;

class Stack
{
private:
    vector<int> v;

public:
    void push(int data)
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

    int top()
    {
        return v[v.size() - 1];
    }
};

int main()
{
    Stack s;
    int n, data;
    cout << "Enter the number of elements you want to enter in stack: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data: ";
        cin >> data;
        s.push(data);
    }

    // Printing the content of the stack by popping each element
    cout << "The contents of the stack are: " << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}