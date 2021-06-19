#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    for (int i = 0; i < 6; i++)
    {
        s.push(i); // O(1)
    }
    while (!s.empty())
    {
        cout << s.top() << ", "; // O(1)
        s.pop();                 // O(1)
    }
    return 0;
}