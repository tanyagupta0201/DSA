// Given n number of cars with their x coordinate and y coordinate. We need to sort the cars according to their distance from the origin.

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> car1, pair<int, int> car2)
{
    int d1 = car1.first * car1.first + car1.second * car1.second;
    int d2 = car2.first * car2.first + car2.second * car2.second;

    // Sorting according to x coordinate
    if (d1 == d2)
    {
        return car1.first < car2.first;
    }
    return d1 < d2;
}

int main()
{
    int n;
    cout << "Enter the number of cars: ";
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end(), compare);

    // for each loop
    for (auto p : v)
    {
        cout << "Car " << p.first << "," << p.second << endl;
    }
    return 0;
}