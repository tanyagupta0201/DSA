#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int w, h, n;
    int x[40010], y[40010];

    while (t--)
    {
        cin >> w >> h >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x[i] >> y[i];
        }

        // Sorting of the coordinates
        sort(x, x + n);
        sort(y, y + n);

        // delta x and delta y
        int dx = x[0] - 1;
        int dy = y[0] - 1;

        for (int i = 1; i < n; i++)
        {
            dx = max(dx, x[i] - x[i - 1] - 1);
            dy = max(dy, y[i] - y[i - 1] - 1);
        }

        // Corner Case (last tower to grid end)
        dx = max(dx, w - x[n - 1]);
        dy = max(dy, h - y[n - 1]);

        cout << dx * dy << endl; // Print the area of the largest rectangle
    }

    return 0;
}