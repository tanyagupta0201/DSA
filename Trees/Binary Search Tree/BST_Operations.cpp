#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Accepts the old root node and data and returns the new root node
node *Insert_In_BST(node *root, int data)
{
    // Base Case
    if (root == NULL)
    {
        return new node(data); // Create a new node and return it
    }

    // Recursive Case
    // Insert in the sub tree and update pointer
    if (data <= root->data)
    {
        root->left = Insert_In_BST(root->left, data);
    }
    else
    {
        root->right = Insert_In_BST(root->right, data);
    }
    return root;
}

node *build()
{
    // Read a list of numbers till -1 and also these numbers will be inserted into BST
    int d;
    cin >> d;
    node *root = NULL;

    while (d != -1)
    {
        root = Insert_In_BST(root, d);
        cin >> d;
    }
    return root;
}

void BFS(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node *f = q.front();

        if (f == NULL)
        {
            cout << endl;
            q.pop();

            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data << " ";
            q.pop();

            if (f->left)
            {
                q.push(f->left);
            }

            if (f->right)
            {
                q.push(f->right);
            }
        }
    }
}

// Inorder print
void Inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    Inorder(root->left);
    cout << root->data << ",";
    Inorder(root->right);
}

// Preorder print
void Preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ",";
    Preorder(root->left);
    Preorder(root->right);
}

// Postorder print
void Postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    Postorder(root->left);
    cout << root->data << ",";
    Postorder(root->right);
}

// Searching for a data
bool search(node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == data)
    {
        return true;
    }

    // Recursively search in left and right subtree
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

// Delete a node in Binary Search Tree
node *DeleteInBST(node *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (data < root->data)
    {
        root->left = DeleteInBST(root->left, data);
        return root;
    }
    else if (root->data == data)
    {
        // 3 Cases
        // 1. Node with 0 children
        if (root->left == NULL and root->right == NULL)
        {
            return NULL;
        }

        // 2.Node with 1 child
        if (root->left != NULL and root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }

        if (root->left == NULL and root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }

        // 3. Node with 2 children
        // Find inorder successor from right subtree
        node *replace = root->right;
        while (replace->left != NULL)
        {
            replace = replace->left;
        }
        root->data = replace->data;
        root->right = DeleteInBST(root->right, replace->data);
        return root;
    }
    else
    {
        // if data > root->data
        root->right = DeleteInBST(root->right, data);
        return root;
    }
}

// To check if the tree is BST or not
bool isBST(node *root, int minV = INT_MIN, int maxV = INT_MAX)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV))
    {
        return true;
    }
    return false;
}

class LinkedList
{
public:
    node *head;
    node *tail;
};

// Convert a BST into a sorted linked list
LinkedList flattened(node *root)
{
    LinkedList l;

    if (root == NULL)
    {
        l.head = l.tail = NULL;
        return l;
    }

    // Leaf Node
    if (root->left == NULL and root->right == NULL)
    {
        l.head = l.tail = root;
        return l;
    }

    // Left is not NULL but right is NULL
    if (root->left != NULL and root->right == NULL)
    {
        LinkedList leftLL = flattened(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
        return l;
    }

    // Left is NULL but right is  not NULL
    if (root->left == NULL and root->right != NULL)
    {
        LinkedList RightLL = flattened(root->right);
        root->right = RightLL.head;

        l.head = root;
        l.tail = RightLL.tail;
        return l;
    }

    // Both sides are not NULL
    LinkedList LeftLL = flattened(root->left);
    LinkedList RightLL = flattened(root->right);

    LeftLL.tail->right = root;
    root->right = RightLL.head;

    l.head = LeftLL.head;
    l.tail = RightLL.tail;
    return l;
}

int main()
{
    node *root = build();
    cout << "The Inorder Traversal is: ";
    Inorder(root);
    cout << endl;

    cout << "The Preorder Traversal is: ";
    Preorder(root);
    cout << endl;

    cout << "The Postorder Traversal is: ";
    Postorder(root);
    cout << endl;

    BFS(root);
    cout << endl;

    int s;
    cout << "Enter the data to be searched: ";
    cin >> s;

    if (search(root, s))
    {
        cout << "Present in the tree !!" << endl;
    }
    else
    {
        cout << "Not present in the tree !!" << endl;
    }

    if (isBST(root))
    {
        cout << "Yes, it is a BST !!" << endl;
    }
    else
    {
        cout << "Not a BST!" << endl;
    }

    int del;
    cout << "Enter the data to be deleted: ";
    cin >> del;
    root = DeleteInBST(root, del);
    cout << endl;
    cout << "The Inorder Traversal is: ";
    Inorder(root);
    cout << endl;
    BFS(root);
    cout << endl;

    LinkedList l = flattened(root);
    node *temp = l.head;

    while (temp != NULL)
    {
        cout << temp->data << " --> ";
        temp = temp->right;
    }
    cout << endl;

    return 0;
}
