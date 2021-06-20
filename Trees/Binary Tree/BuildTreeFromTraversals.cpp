// Build Tree from traversals (Inorder and Preorder)

#include <iostream>
#include <queue>
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
        left = NULL;
        right = NULL;
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

node *createTreeFromTrav(int *inorder, int *preorder, int start, int end)
{
    // We need to make a static or global variable, if a local variable is made it will backtrack but we dont want to backtrack because the node used once is used.
    static int i = 0;

    // Base Case
    if (start > end)
    {
        return NULL;
    }

    // Recursive Case
    node *root = new node(preorder[i]); // Created a new root from Preorder

    int index = -1; // As we dont know at which index it is present

    for (int j = start; start <= end; j++)
    {
        if (inorder[j] == preorder[i])
        {
            index = j;
            break;
        }
    }

    i++;

    root->left = createTreeFromTrav(inorder, preorder, start, index - 1);
    root->right = createTreeFromTrav(inorder, preorder, index + 1, end);
    return root;
}

int main()
{
    int in[] = {3, 2, 8, 4, 1, 6, 7, 5};
    int pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
    int n = sizeof(in) / sizeof(int);

    node *root = createTreeFromTrav(in, pre, 0, n - 1);
    BFS(root);
    return 0;
}