// Breadth First Search (Complexity: O(n))
// Level Order Traversal

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

void BFS(node *root)
{
    queue<node *> q;
    q.push(root); // We don't have to push root->data as it is of node type

    while (!q.empty())
    {
        node *f = q.front();
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

    BFS(root);
    return 0;
}