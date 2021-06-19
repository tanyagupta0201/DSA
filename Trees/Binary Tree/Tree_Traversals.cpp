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
        left = NULL;
        right = NULL;
    }
};

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

void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Postorder(root->left);
    Postorder(root->right);
}

void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Inorder(root->left);
    Inorder(root->right);
}

/*
             1
           /   \
          2     3
        /  \   /  \
       4    5  6   7
*/

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
    cout << "Preorder Traversal: ";
    Postorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    Inorder(root);
    cout << endl;
    return 0;
}