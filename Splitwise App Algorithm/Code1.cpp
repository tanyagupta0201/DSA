#include <bits/stdc++.h>
using namespace std;

int main()
{
    int friends, no_of_transactions, cnt = 0;

    cout << "Enter Number of transactions: ";
    cin >> no_of_transactions;

    cout << "Enter number of friends: ";
    cin >> friends;

    // Making a 1D Array to store the net amount that each person will have to take at the end
    int net[10000] = {0};

    int x, y, amount;

    while (no_of_transactions--)
    {
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }

    multiset<int> m;

    // Init a list and sort it
    for (int i = 0; i < friends; i++)
    {
        if (net[i] != 0)
        {
            m.insert(net[i]);
        }
    }

    // Pop out two persons from left and right and try to settle them
    while (!m.empty())
    {
        auto low = m.begin();
        auto high = prev(m.end()); // as the pointer points at the position after the last value so we used prev

        int debit = *low;
        int credit = *high;

        // Erase
        m.erase(low);
        m.erase(high);

        // Settlement
        int settlement_amount = min(-debit, credit);
        cnt++;

        // Settlement amount from donor to acceptor
        debit += settlement_amount;
        credit -= settlement_amount;

        if (debit != 0)
        {
            m.insert(debit);
        }

        if (credit != 0)
        {
            m.insert(credit);
        }
    }

    // Number of Transactions
    cout << cnt << endl;

    return 0;
}