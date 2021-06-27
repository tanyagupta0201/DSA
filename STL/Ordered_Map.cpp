#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> m;

    // Insert
    m.insert(make_pair("Mango", 100));

    pair<string, int> p;
    p.first = "Apple";
    p.second = 120;
    m.insert(p);

    m["Banana"] = 30;

    // Search
    string fruit;
    cout << "Enter the fruit to be searched: ";
    cin >> fruit;

    // Update the price
    m[fruit] += 30;

    map<string, int>::iterator it = m.find(fruit); // auto keyword can also be used
    if (it != m.end())
    {
        cout << "Price of " << fruit << " is " << m[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present !!" << endl;
    }

    m.erase(fruit); // to delete the fruit

    // Another way to find a particular map
    // it stores unique keys only once
    if (m.count(fruit))
    {
        cout << "Price is " << m[fruit] << endl;
    }
    else
    {
        cout << "Could not find the fruit !!" << endl;
    }
    cout << endl;

    // Adding some more fruits
    m["Pineapple"] = 90;
    m["Litchi"] = 76;
    m["Orange"] = 110;

    // Iterate over all the key values
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " and " << it->second << endl;
    }
    cout << endl;

    // for each loop
    for (auto p : m)
    {
        cout << p.first << " : " << p.second << endl;
    }
    return 0;
}