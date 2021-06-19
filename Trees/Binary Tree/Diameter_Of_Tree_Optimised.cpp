// Optimised Solution to calculate the height of the tree

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Pair
{
public:
    int height;
    int diameter;
};

Pair FastDiameter(node *root)
{
    Pair p;
    if (root == NULL)
    {
        p.diameter = p.height = 0;
        return p;
    }

    // Otherwise
    Pair left = FastDiameter(root->left);
    Pair right = FastDiameter(root->right);

    p.height = max(left.height, right.height) + 1;
    p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
    return p;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    Pair p = FastDiameter(root);
    cout << "The height of the tree is " << p.height << endl;
    cout << "The diameter of the tree is " << p.diameter << endl;
    return 0;
}