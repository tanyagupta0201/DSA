#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++)
    {
        s2.push(s1.top());
        s1.top();
    }
}

void ReverseStack(stack<int> &s1)
{
    // Helper Stack
    stack<int> s2;

    int n = s1.size();

    for (int i = 0; i < n; i++)
    {
        // Pick an element from top and store it in a variable
        int x = s1.top();
        s1.pop();

        // Transfer n-i-1 elements from stack s1 to s2
        transfer(s1, s2, n - i - 1);

        // Insert the element x in s1
        s1.push(x);

        // Transfer n-i-1 elements from stack s2 to s1
        transfer(s2, s1, n - i - 1);
    }
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
}

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

    ReverseStack(s);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    /*  for (int i = 0; i < 6; i++)
    {
        s.push(i); // O(1)
    }
    cout << "Contents of the stack are: " << endl;
    while (!s.empty())
    {
        cout << s.top() << ", "; // O(1)
        s.pop();                 // O(1)
    }
    cout << endl;
    ReverseStack(s);
    cout << "Reverse Order: " << endl;
    while (!s.empty())
    {
        cout << s.top() << ", "; // O(1)
        s.pop();                 // O(1)
    }
    */
    return 0;
}