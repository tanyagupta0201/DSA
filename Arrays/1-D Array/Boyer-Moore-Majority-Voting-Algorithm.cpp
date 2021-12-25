/*
    The Boyer-Moore voting algorithm is one of the popular optimal algorithms which is used to find the majority element among the given elements that have more than N/ 2 occurrences. This works perfectly fine for finding the majority element which takes 2 traversals over the given elements, which works in O(N) time complexity and O(1) space complexity.
*/

#include <bits/stdc++.h>
using namespace std;

int findMajority(int a[], int n)
{
    int votes = 0, candidate = -1, count = 0;

    for (int i = 0; i < n; i++)
    {
        if (votes == 0)
        {
            candidate = a[i];
            votes = 1;
        }
        else if (candidate == a[i])
        {
            votes++;
        }
        else
        {
            votes--;
        }
    }

    // Checking if majority candidate occurs more than n/2 times
    for (int i = 0; i < n; i++)
    {
        if (a[i] == candidate)
            count++;
    }

    if (count > n / 2)
        return candidate;

    return -1;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[50];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Majority element: " << findMajority(a, n) << endl;

    return 0;
}

/*
Enter the size of the array: 7
Enter the elements of the array: 1 2 1 1 6 1 4
Majority element: 1
*/