#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *right;
    node *left;

    node(int val)
    {
        data = val;
        right = NULL;
        left = NULL;
    }
};

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
    return;
}

node *BuildFromArray(int *a, int start, int end)
{
    // Base Case
    if (start > end)
    {
        return NULL;
    }

    // Recursive Case
    int mid = (start + end) / 2;
    node *root = new node(a[mid]);

    root->left = BuildFromArray(a, start, mid - 1);
    root->right = BuildFromArray(a, mid + 1, end);
    return root;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(a) / sizeof(int);

    node *root = BuildFromArray(a, 0, n - 1);
    BFS(root);
    return 0;
}