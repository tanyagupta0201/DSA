// Recursive Functions to find the different index of an element if present in the array

#include <bits/stdc++.h>
using namespace std;

// First Method
int firstOcc(int a[], int n, int key)
{
    // Base Case
    if (n == 0)
    {
        return -1;
    }
    // Rec Case
    if (a[0] == key)
    {
        return 0;
    }
    int i = firstOcc(a + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

// Second Method
int firstOccurence(int a[], int i, int n, int key)
{
    // Base Case
    if (i == n)
    {
        return -1;
    }
    // Rec Case
    if (a[i] == key)
    {
        return i;
    }
    return firstOccurence(a, i + 1, n, key);
}

int LastOcc(int a[], int n, int key)
{
    // Base Case
    if (n == 0)
    {
        return -1;
    }
    // Rec Case
    int i = LastOcc(a + 1, n - 1, key);
    if (i == -1)
    {
        if (a[0] == key)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    return i + 1;
}

int AllOccurences(int a[], int i, int n, int key)
{
    // Base Case
    if (i == n)
    {
        return -1;
    }
    // Rec Case
    if (a[i] == key)
    {
        cout << i << " ";
    }
    return AllOccurences(a, i + 1, n, key);
}

int main()
{
    int n, key, i = 0;
    cout << "Enter the element to be searched: ";
    cin >> key;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[50];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // First occurence of the element(key) which is to searched
    cout << firstOcc(a, n, key); // First Method
    cout << endl;

    cout << firstOccurence(a, i, n, key); // Second Method
    cout << endl;

    // Last occurence of the element(key) which is to searched
    cout << LastOcc(a, n, key);
    cout << endl;

    // All occurences of the element(key) which is to be searched
    AllOccurences(a, i, n, key);

    return 0;
}