#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class heap
{
    vector<int> v;
    bool minHeap;

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

    void heapify(int index)
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
            heapify(min_index);
        }
    }

public:
    heap(int default_size = 10, bool type = true) // false in case of MaxHeap
    {
        v.reserve(default_size);
        v.push_back(-1); // To reserve the 0th index of the array
        minHeap = type;
    }

    void push(int d)
    {
        v.push_back(d);
        int index = v.size() - 1; // Gives the last element as the indexing starts from zero which is blocked
        int parent = index / 2;

        // Keep pushing to the top till you reach a root node or stop midway because the current element is already greater than the present
        while (index > 1 and compare(v[index], v[parent]))
        {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1]; // Returns the topmost element
    }

    void pop()
    {
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back(); // Removes the last element
        heapify(1);
    }

    bool empty()
    {
        return v.size() == 1;
    }
};

int main()
{
    heap h;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    // Remove all elements one by one
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }

    return 0;
}