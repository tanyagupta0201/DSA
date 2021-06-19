#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};
    char ch;
    cin >> ch;

    // The string is terminated by a dot
    while (ch != '.')
    {
        // Logic
        // Insert the character in the queue q and freq table
        q.push(ch);
        freq[ch - 'a']++;

        // Query
        while (!q.empty())
        {
            int index = q.front() - 'a';
            if (freq[index] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << " ";
                break;
            }
        }

        // If q is empty
        if (q.empty())
        {
            cout << "-1"
                 << " ";
        }
        cin >> ch;
    }
    return 0;
}