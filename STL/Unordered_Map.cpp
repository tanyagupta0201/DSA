// Unordered Maps - Insertion, Deletion(Erase), Find in O(1) time on average
// If the table size is large, rehashing is done then it takes O(n) time

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string, int> um;

    // Insert
    um.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    um.insert(p);

    um["Banana"] = 30;

    // Search
    string fruit;
    cout << "Enter the fruit to be searched: ";
    cin >> fruit;

    // Update the price
    um[fruit] += 30;

    unordered_map<string, int>::iterator it = um.find(fruit); // auto keyword can also be used
    if (it != um.end())
    {
        cout << "Price of " << fruit << " is " << um[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present !!" << endl;
    }

    um.erase(fruit); // to delete the fruit

    // Another way to find a particular map
    // it stores unique keys only once
    if (um.count(fruit))
    {
        cout << "Price is " << um[fruit] << endl;
    }
    else
    {
        cout << "Could not find the fruit !!" << endl;
    }
    cout << endl;

    // Adding some more fruits
    um["Pineapple"] = 90;
    um["Litchi"] = 76;
    um["Orange"] = 110;

    // Iterate over all the key values
    for (auto it = um.begin(); it != um.end(); it++)
    {
        cout << it->first << " and " << it->second << endl;
    }
    cout << endl;

    // for each loop
    for (auto p : um)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}