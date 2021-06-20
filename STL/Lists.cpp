#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> l;
    list<int> l1{1, 2, 3, 4, 5, 6};
    list<string> l2{"apple", "mango", "grapes", "mango", "orange", "guava"};

    // Inserts at the end of the list
    l2.push_back("banana");
    l1.push_back(7);

    for (auto x : l1)
    {
        cout << x << " -> ";
    }
    cout << endl;

    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    l2.sort(); // Sorts the list lexicographically
    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    l2.reverse(); // Reverses the list
    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    l2.push_front("Kiwi"); // Inserts at first index
    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    cout << l1.front() << endl; // Prints the first element
    cout << l2.back() << endl;  // Prints the last element
    l2.pop_back();

    // Iterate over the list and print the data
    for (auto it = l2.begin(); it != l2.end(); it++)
    {
        cout << (*it) << " -> ";
    }
    cout << endl;

    // Remove a fruit
    string f;
    cout << "Enter fruit you want to remove: ";
    cin >> f;
    l2.remove(f);
    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    // Erase one or more elements
    // auto it = l2.begin() + 3; (It is not possible, direct access is not possible in lists)
    auto it = l2.begin();
    it++;
    it++;
    it++;
    it++;
    it++;
    l2.erase(it);

    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;

    // We can insert elements in the list
    it = l2.begin();
    it++;
    l2.insert(it, "Strawberry");
    for (auto x : l2)
    {
        cout << x << " -> ";
    }
    cout << endl;
    return 0;
}