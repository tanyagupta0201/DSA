#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // priority_queue<int> pq;                            // Max Priority
    priority_queue<int, vector<int>, greater<int>> pq; // Min Priority

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        pq.push(no); // O(LogN)
    }

    // Remove the elements from the heap
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}