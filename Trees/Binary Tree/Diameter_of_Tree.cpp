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

void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

int Height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int Left_height = Height(root->left);
    int right_height = Height(root->right);
    return max(Left_height, right_height) + 1;
}

int Diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int h1 = Height(root->left);
    int h2 = Height(root->right);
    int op1 = h1 + h2;
    int op2 = Diameter(root->left);
    int op3 = Diameter(root->right);

    return max(op1, max(op2, op3));
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
    cout << "The height of the tree is: ";
    cout << Height(root) << endl;
    cout << "The diameter of the tree is: ";
    cout << Diameter(root) << endl;
    return 0;
}