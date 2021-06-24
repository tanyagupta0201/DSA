/*
    Given N ropes of different sizes, we have to join the ropes together.
    The cost of joining 2 ropes of different sizes A and B is (A + B).
    Find minimum cost to join all the ropes together.

*/

#include <bits/stdc++.h>
using namespace std;

int join_ropes(int ropes[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n); // To make it a min heap as it it maxHeap by default

    int cost = 0;

    while (pq.size() > 1)
    {
        int A = pq.top();
        pq.pop();

        int B = pq.top();
        pq.pop();

        // Length and cost both are same
        int new_rope = (A + B); // Length
        cost = cost + new_rope; // Cost
        pq.push(new_rope);
    }
    return cost;
}

int main()
{
    int ropes[] = {4, 3, 2, 6};
    int n = 4;
    cout << join_ropes(ropes, n) << endl;
    return 0;
}