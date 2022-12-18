// https://takeuforward.org/data-structure/boundary-traversal-of-a-binary-tree/

/*
    1. Add left nodes leaving the leaf nodes.
    2. Add Leaf Nodes by preorder traversal.
        Please note that we want the leaves to come in a specific order which is bottom-left to top-right,
        therefore a level order traversal will not work because it will print the upper-level leaves first.
        Therefore, we use a preorder traversal.
    3. Add Right nodes in reverse order leaving the leaf nodes.
*/

class solution
{

    bool isLeaf(Node *root)
    {
        return !root->left && !root->right;
    }

    void AddLeftBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->left;

        while (curr)
        {
            if (!isLeaf(curr))
                res.push_back(curr->data);

            if (curr->left)
                curr = curr->left;
            else
                curr = curr->right;
        }
    }

    void AddLeaves(Node *root, vector<int> &res)
    {
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }

        if (root->left)
            AddLeaves(root->left, res);

        if (root->right)
            AddLeaves(root->right, res);
    }

    void AddRightBoundary(Node *root, vector<int> &res)
    {
        Node *curr = root->right;
        vector<int> temp;

        while (curr)
        {
            if (!isLeaf(curr))
                temp.push_back(curr->data);

            if (curr->right)
                curr = curr->right;
            else
                curr = curr->left;
        }

        for (int i = temp.size(); i >= 0; i--)
        {
            res.push_back(temp[i]);
        }
    }

public:
    vector<int> printBoundary(Node *root)
    {
        vector<int> res;

        if (root == NULL)
            return res;

        if (!isLeaf(root))
            res.push_back(root->data);

        AddLeftBoundary(root, res);
        AddLeaves(root, res);
        AddRightBoundary(root, res);

        return res;
    }
}