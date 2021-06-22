#include <bits/stdc++.h>
using namespace std;

bool minHeap = false; // It will make MaxHeap
// bool minHeap = true; // To make MinHeap

bool compare(int a, int b)
{
    if (minHeap)
    {
        return a < b;
    }
    else
    {
        return a > b;
    }
}

void print(vector<int> v)
{
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void heapify(vector<int> &v, int index)
{
    int left = 2 * index;
    int right = (2 * index) + 1;

    int min_index = index;
    int last = v.size() - 1;

    if (left <= last and compare(v[left], v[index]))
    {
        min_index = left;
    }

    if (right <= last and compare(v[right], v[min_index]))
    {
        min_index = right;
    }

    if (min_index != index)
    {
        swap(v[index], v[min_index]);
        heapify(v, min_index);
    }
}

// O(n)
void BuildHeapOptimised(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 1; i--)
    {
        heapify(v, i);
    }
}

int main()
{
    vector<int> v{-1, 10, 20, 5, 6, 1, 8, 9, 4};
    print(v);
    BuildHeapOptimised(v);
    print(v);
    return 0;
}