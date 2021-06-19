// Sorting of Car on the basis of distance from origin (by custom class) (user defined)

#include <bits/stdc++.h>
using namespace std;

class car
{
public:
    string car_name;
    int x, y;
    car()
    {
    }
    car(string n, int x, int y)
    {
        car_name = n;
        this->x = x;
        this->y = y;
    }
    int dist()
    {
        // Returns square of distance from origin
        return x * x + y * y;
    }
};

bool compare(car A, car B)
{
    int da = A.dist();
    int db = B.dist();

    // If distance is same sort according to length
    if (da == db)
    {
        return A.car_name.length() < B.car_name.length();
    }
    // else sort according to distance from the origin
    return da < db;
}

int main()
{
    int n;
    cin >> n;
    vector<car> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        string name;
        cin >> name >> x >> y;
        car temp(name, x, y);
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), compare);

    // For each loop
    for (auto c : v)
    {
        cout << "Car: " << c.car_name << " Distance: " << c.dist() << " Location: " << c.x << ", " << c.y << endl;
    }
    return 0;
}