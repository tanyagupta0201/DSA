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

// Preorder Traversal
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

// Postorder traversal
void Postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

// Inorder Traversal
void Inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

// To calculate the height of the tree
int Height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left_height = Height(root->left);
    int right_height = Height(root->right);
    if (left_height > right_height)
    {
        return left_height + 1; // We have added 1 because root node is included
    }
    else
    {
        return right_height + 1;
    }
}

// To print the Kth Level of the tree
void print_KthLevel(struct node *root, int k)
{
    if (root == NULL)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    print_KthLevel(root->left, k - 1);
    print_KthLevel(root->right, k - 1);
}

// To print all levels of the tree
void printAllLevels(node *root)
{
    int H = Height(root);

    for (int i = 0; i < H; i++)
    {
        print_KthLevel(root, i);
        cout << endl;
    }
    return;
}

/*
             1          Level = 0
           /   \
          2     3       Level = 1
        /  \   /  \
       4    5 6    7    Level = 2
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
    cout << "The height of the tree is: ";
    cout << Height(root) << endl;
    int k;
    cout << "Enter k: ";
    cin >> k;
    print_KthLevel(root, k);
    cout << endl;
    cout << "All the levels of the tree are: " << endl;
    printAllLevels(root); // Complexity: O(n^2)
    return 0;
}
