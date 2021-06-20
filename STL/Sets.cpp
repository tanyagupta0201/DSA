#include <iostream>
#include <set>
using namespace std;

int main()
{
    int arr[] = {2, 6, 3, 1, 7, 9, 9, 1, 2, 77};
    int n = sizeof(arr) / sizeof(int);

    set<int> s;

    // Inserting elements
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    // Printing all elements
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << ", "; // Sets are ordered and unique
    }
    cout << endl;

    // Erase Function
    // 1st Way
    s.erase(3);

    // 2nd Way
    auto it = s.find(9);
    s.erase(it);

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << ", ";
    }
    cout << endl;
    return 0;
}