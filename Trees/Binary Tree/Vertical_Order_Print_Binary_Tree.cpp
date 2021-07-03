// Print a tree in vertical Order

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

// Pass it by reference
void VerticalOrderPrint(node *root, int d, map<int, vector<int>> &m)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Otherwise
    m[d].push_back(root->data);
    VerticalOrderPrint(root->left, d - 1, m);
    VerticalOrderPrint(root->right, d + 1, m);
    return;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->right->right = new node(9);
    root->left->right->right = new node(8);

    map<int, vector<int>> m;
    int d = 0;
    VerticalOrderPrint(root, d, m);

    for (auto p : m)
    {
        cout << p.first << " --> ";
        for (int x : p.second)
        {
            cout << x << ", ";
        }
        cout << endl;
    }
    return 0;
}