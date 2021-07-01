#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int n, k, i;

    //vector initialisition
    vector<int> v;
    cin >> n;
    for (i = 0; i < 2 * n; i++)
    {
        cin >> k;

        //inserting into vector
        v.push_back(k);
    }

    //sorting the vector
    sort(v.begin(), v.end());

    //accessing a particulat element form a vector
    cout << v[n - 1];

    return 0;
}