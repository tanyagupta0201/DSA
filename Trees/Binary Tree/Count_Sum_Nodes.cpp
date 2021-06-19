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

int count_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

int sum_nodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return root->data + sum_nodes(root->left) + sum_nodes(root->right);
}

void Preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
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
    cout << "Preorder Traversal: ";
    Preorder(root);
    cout << endl;
    cout << "Number of nodes: ";
    cout << count_nodes(root) << endl;
    cout << endl;
    cout << "Sum of nodes: ";
    cout << sum_nodes(root);
    return 0;
}