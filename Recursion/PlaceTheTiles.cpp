// Given a wall of size 4 X N and tiles of size (1, 4) and (4, 1).
// In how many ways can you build the wall ?

#include <bits/stdc++.h>
using namespace std;

int PlaceTheTiles(int n)
{
    if (n <= 3)
    {
        return 1;
    }

    // Vertical Way + Horizontal Way
    return PlaceTheTiles(n - 1) + PlaceTheTiles(n - 4);
}

int main()
{
    int n;
    cout << "Enter the number of bricks: ";
    cin >> n;
    cout << PlaceTheTiles(n);
    return 0;
}
