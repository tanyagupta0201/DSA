/*  
    Find a pair with maximum XOR

    input[] = {3, 10,5,25,2,8}
    output = 5 ^25 = 28

    (Find two numbers with most significant bits from left side)

*/

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    node *left;  // for 0
    node *right; // for 1
};

class trie
{
    node *root;

public:
    trie()
    {
        root = new node();
    }

    // Insert Function
    // Taking 32 bit integer
    void insert(int n)
    {
        node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            // Extract each bit
            int bit = (n >> i) & 1;

            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else
            {
                // Bit is 1
                if (temp->right == NULL)
                {
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }

    // helper function to max xor
    int max_xor_helper(int value)
    {
        int curr_ans = 0;
        node *temp = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (value >> j) & 1;

            if (bit == 0)
            {
                // Find a complementary value
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    curr_ans += (1 << j);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                // Current bit is 1
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    curr_ans += (1 << j);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return curr_ans;
    }

    int max_xor(int *input, int n)
    {
        int max_xor = 0;
        for (int i = 0; i < n; i++)
        {
            int val = input[i];
            insert(val);
            int curr_xor = max_xor_helper(val);
            cout << curr_xor << " ";
            max_xor = max(curr_xor, max_xor);
        }
        return max_xor;
    }
};

int main()
{
    // Max XOR pair
    int input[] = {3, 10, 5, 25, 2, 8};
    trie t;
    cout << t.max_xor(input, 6) << endl;
    return 0;
}