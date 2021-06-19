// AVL Tree is also called Height Balanced Tree
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *right;
    struct node *left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

class HBPair
{
public:
    int height;
    bool balance;
};

HBPair isHeightBalanced(node *root)
{
    HBPair p;
    if (root == NULL)
    {
        p.height = 0;
        p.balance = true;
        return p;
    }

    // Recursive Case
    HBPair left = isHeightBalanced(root->left);
    HBPair right = isHeightBalanced(root->right);

    p.height = max(left.height, right.height) + 1;

    if (abs(left.height - right.height) <= 1 and left.balance and right.balance)
    {
        p.balance = true;
    }
    else
    {
        p.balance = false;
    }
    return p;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->left->left = new node(4);
    root->left->left->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    if (isHeightBalanced(root).balance)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}