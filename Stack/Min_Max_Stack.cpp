#include <bits/stdc++.h>
using namespace std;

class MinMaxStack
{
    vector<int> stack;
    vector<int> min_stack;
    vector<int> max_stack;

public:
    void push(int data)
    {
        int curr_min = data;
        int curr_max = data;

        if (min_stack.size())
        {
            if (max_stack.size() - 1 > data)
            {
                curr_max = max_stack.size() - 1;
            }
            if (min_stack.size() - 1 < data)
            {
                curr_min = min_stack.size() - 1;
            }
        }
        stack.push_back(data);
        min_stack.push_back(data);
        max_stack.push_back(data);
    }

    int get_min()
    {
        return min_stack.size() - 1;
    }

    int get_max()
    {
        return max_stack.size() - 1;
    }

    int top()
    {
        return stack[stack.size() - 1];
    }

    bool empty()
    {
        return stack.size() == 0;
    }

    void pop()
    {
        stack.pop_back();
        min_stack.pop_back();
        max_stack.pop_back();
    }

    void print()
    {
        cout << "The stack is: ";
        for (int x : stack)
        {
            cout << x << " ";
        }
        cout << endl;

        cout << "The min stack is: ";
        for (int x : max_stack)
        {
            cout << x << " ";
        }
        cout << endl;

        cout << "The max stack is: ";
        for (int x : min_stack)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};
int main()
{
    MinMaxStack s;
    s.push(2);
    s.push(22);
    s.push(9);
    s.push(11);
    s.push(6);
    s.push(7);
    s.push(1);
    s.print();
    cout << s.get_max() << endl;
    cout << s.get_min() << endl;
    s.pop();
    cout << s.get_max() << endl;
    cout << s.get_min() << endl;
    s.pop();
    s.pop();
    cout << s.get_min() << endl;
    cout << s.top() << endl;
    return 0;
}