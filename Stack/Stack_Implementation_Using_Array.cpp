#include <bits/stdc++.h>
using namespace std;
#define MAX 100

class Stack
{
    int top;

public:
    int a[MAX]; // Maximum size of the stack
    Stack()
    {
        top = -1;
    }
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
};

void Stack ::push(int data)
{
    if (top >= MAX)
    {
        cout << "Stack Overflow !!";
    }
    else
    {
        top++;
        a[top] = data;
        cout << data << " pushed into the stack" << endl;
    }
}

int Stack ::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow !!" << endl;
        return 0;
    }
    else
    {
        int x = a[top];
        top--;
        return x;
    }
}

int Stack ::peek()
{
    if (top < 0)
    {
        cout << "Stack is empty !!" << endl;
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout << s.pop() << " popped from the stack" << endl;

    cout << "The top element of the stack is: " << s.peek() << endl;
    // Print all the contents of the stack
    cout << "The contents of the stack are: ";
    while (!s.isEmpty())
    {
        // Print the top element of the stack
        cout << s.peek() << " ";
        // Remove the top element of the stack
        s.pop();
    }
    return 0;
}