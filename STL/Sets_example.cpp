#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<pair<int, int>> s;

    s.insert(make_pair(12, 9));
    s.insert(make_pair(2, 8));
    s.insert(make_pair(12, 19));
    s.insert(make_pair(62, 97));
    s.insert(make_pair(12, 2));
    s.insert(make_pair(12, 7));
    s.insert(make_pair(13, 0));

    s.erase(make_pair(13, 0));
    s.insert(make_pair(13, 2));

    // It will be printed in order
    for (auto p : s)
    {
        cout << p.first << " and " << p.second << endl;
    }
    cout << endl;
    auto it = s.lower_bound(make_pair(12, 2));
    cout << it->first << " and " << it->second << endl;

    it = s.upper_bound(make_pair(12, 7));
    cout << it->first << " and " << it->second << endl;
    return 0;
}