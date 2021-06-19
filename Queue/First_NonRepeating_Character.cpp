#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[27] = {0};
    char ch;
    cin >> ch;

    while (ch != '.')
    {
        q.push(ch);
        freq[ch - 'a']++;

        /* while (!q.empty())
        {
            int index = q.front() - 'a';
            if (!(freq[index] > 1))
            {
                cout << q.front() << endl;
                break;
            }
            else
            {
                break;
            }
        }*/
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
        cin >> ch;
    }

    return 0;
}